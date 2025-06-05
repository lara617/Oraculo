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

        # Usar o executável C++
        exe_path = 'oraculo.exe'
        print(f"Caminho do executável: {exe_path}", file=sys.stderr)

        try:
            print("Iniciando execução do programa...", file=sys.stderr)
            print(f"Pergunta enviada: {pergunta}", file=sys.stderr)
            
            # Executar o programa C++
            resultado = subprocess.run(
                [exe_path],
                input=pergunta,
                capture_output=True,
                text=True,
                timeout=10
            )

            print(f"Código de retorno: {resultado.returncode}", file=sys.stderr)
            print(f"Saída do programa: {resultado.stdout}", file=sys.stderr)
            print(f"Erro do programa: {resultado.stderr}", file=sys.stderr)

            # Verificar se houve erro
            if resultado.stderr:
                return jsonify({
                    'error': f'Erro ao processar consulta: {resultado.stderr}',
                    'stdout': resultado.stdout,
                    'stderr': resultado.stderr
                }), 500

            # Processar a saída
            resposta = resultado.stdout.strip()
            print(f"Resposta final: {resposta}", file=sys.stderr)
            
            return jsonify({
                'resposta': resposta
            })

        except subprocess.TimeoutExpired as te:
            print(f"Tempo limite excedido: {str(te)}", file=sys.stderr)
            return jsonify({
                'error': 'Tempo limite excedido ao processar a consulta',
                'timeout': str(te)
            }), 500
        except subprocess.CalledProcessError as cpe:
            print(f"Erro de processo: {str(cpe)}", file=sys.stderr)
            return jsonify({
                'error': f'Erro ao executar o programa: {str(cpe)}',
                'output': cpe.output,
                'stderr': cpe.stderr
            }), 500
        except Exception as e:
            print(f"Erro ao executar subprocess: {str(e)}", file=sys.stderr)
            print(f"Traceback: {traceback.format_exc()}", file=sys.stderr)
            return jsonify({
                'error': f'Erro ao executar o programa: {str(e)}',
                'traceback': traceback.format_exc()
            }), 500

    except Exception as e:
        print(f"Erro geral: {str(e)}", file=sys.stderr)
        print(f"Traceback: {traceback.format_exc()}", file=sys.stderr)
        return jsonify({
            'error': str(e),
            'traceback': traceback.format_exc()
        }), 500

if __name__ == '__main__':
    print("Iniciando servidor...", file=sys.stderr)
    print(f"Diretório atual: {os.getcwd()}", file=sys.stderr)
    print(f"Arquivos no diretório: {os.listdir('.')}", file=sys.stderr)
    app.run(host='localhost', port=5000, debug=True)

if __name__ == '__main__':
    print("Iniciando servidor...", file=sys.stderr)
    print(f"Diretório atual: {os.getcwd()}", file=sys.stderr)
    print(f"Arquivos no diretório: {os.listdir('.')}", file=sys.stderr)
    try:
        app.run(host='localhost', port=5000, debug=True)
    except Exception as e:
        print(f"Erro ao iniciar servidor: {str(e)}", file=sys.stderr)
        print(f"Traceback: {traceback.format_exc()}", file=sys.stderr)
