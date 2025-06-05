from flask import Flask, request, jsonify
import subprocess
import os
import sys
import traceback

app = Flask(__name__, static_url_path='', static_folder='web')

@app.route('/')
def index():
    return app.send_static_file('index.html')

@app.route('/api/consulta', methods=['POST'])
def consulta():
    try:
        data = request.json
        pergunta = data.get('pergunta')
        
        if not pergunta:
            return jsonify({'error': 'Pergunta não fornecida'}), 400

        print(f"Recebida pergunta: {pergunta}", file=sys.stderr)

        # Usar o simulador em Python no lugar do .exe
        exe_path = 'simulador.py'
        print(f"Caminho do script: {exe_path}", file=sys.stderr)

        try:
            print("Iniciando execução do simulador...", file=sys.stderr)
            print(f"Pergunta enviada: {pergunta}", file=sys.stderr)
            
            # Executar o script Python com a pergunta via stdin
            resultado = subprocess.run(
                ['python3', exe_path],
                input=pergunta,
                capture_output=True,
                text=True,
                timeout=10
            )

            print(f"Código de retorno: {resultado.returncode}", file=sys.stderr)
            print(f"Saída do simulador: {resultado.stdout}", file=sys.stderr)
            print(f"Erro do simulador: {resultado.stderr}", file=sys.stderr)

            if resultado.stderr:
                return jsonify({
                    'error': f'Erro ao processar consulta: {resultado.stderr}',
                    'stdout': resultado.stdout,
                    'stderr': resultado.stderr
                }), 500

            resposta = resultado.stdout.strip()
            print(f"Resposta final: {resposta}", file=sys.stderr)
            
            return jsonify({'resposta': resposta})

        except subprocess.TimeoutExpired as te:
            print(f"Tempo limite excedido: {str(te)}", file=sys.stderr)
            return jsonify({'error': 'Tempo limite excedido ao processar a consulta', 'timeout': str(te)}), 500
        except subprocess.CalledProcessError as cpe:
            print(f"Erro de processo: {str(cpe)}", file=sys.stderr)
            return jsonify({'error': f'Erro ao executar o simulador: {str(cpe)}', 'output': cpe.output, 'stderr': cpe.stderr}), 500
        except Exception as e:
            print(f"Erro ao executar subprocess: {str(e)}", file=sys.stderr)
            print(f"Traceback: {traceback.format_exc()}", file=sys.stderr)
            return jsonify({'error': f'Erro ao executar o simulador: {str(e)}', 'traceback': traceback.format_exc()}), 500

    except Exception as e:
        print(f"Erro geral: {str(e)}", file=sys.stderr)
        print(f"Traceback: {traceback.format_exc()}", file=sys.stderr)
        return jsonify({'error': str(e), 'traceback': traceback.format_exc()}), 500

if __name__ == '__main__':
    print("Iniciando servidor...", file=sys.stderr)
    print(f"Diretório atual: {os.getcwd()}", file=sys.stderr)
    print(f"Arquivos no diretório: {os.listdir('.')}", file=sys.stderr)
    try:
        app.run(debug=False, host='0.0.0.0', port=int(os.environ.get('PORT', 5000)))
    except Exception as e:
        print(f"Erro ao iniciar servidor: {str(e)}", file=sys.stderr)
        print(f"Traceback: {traceback.format_exc()}", file=sys.stderr)
