document.addEventListener('DOMContentLoaded', () => {
    const perguntaInput = document.getElementById('pergunta');
    const enviarBtn = document.getElementById('enviar');
    const porqueBtn = document.getElementById('porque');
    const chatMessages = document.getElementById('chatMessages');
    const explicacao = document.getElementById('explicacao');

    // Dados das respostas (simulando o backend)
    const respostas = {
        AMOR: {
            ALEGRE: [
                { resposta: "No amor, a felicidade sorri para ti! Prepara o coração!", explicacao: "O amor é como um sorriso que ilumina o coração." },
                { resposta: "Sim! Um romance vibrante e alegre está a caminho!", explicacao: "Relações felizes são como flores que florescem na primavera." }
            ],
            MISTERIOSO: [
                { resposta: "O destino te reserva um encontro especial...", explicacao: "O amor às vezes se manifesta de formas misteriosas." }
            ]
        },
        TRABALHO: {
            ALEGRE: [
                { resposta: "Sucesso profissional à vista! O teu esforço será recompensado com alegria!", explicacao: "O trabalho duro é como uma semente que floresce com dedicação." }
            ],
            MISTERIOSO: [
                { resposta: "As portas da oportunidade se abrem para ti...", explicacao: "O sucesso profissional é um caminho misterioso que se revela aos preparados." }
            ]
        },
        GERAL: {
            ALEGRE: [
                { resposta: "As estrelas te guiam para um caminho de sucesso!", explicacao: "O universo conspira a teu favor." }
            ],
            MISTERIOSO: [
                { resposta: "O destino te reserva surpresas...", explicacao: "O universo tem planos misteriosos para ti." }
            ]
        }
    };

    // Função para identificar o tema da pergunta
    function identificarTema(pergunta) {
        const perguntaLower = pergunta.toLowerCase();
        
        // Palavras-chave para cada tema
        const temas = {
            AMOR: ["amor", "namoro", "relacionamento", "namorada", "namorado", "esposa", "esposo", "namorar", "casar"],
            TRABALHO: ["trabalho", "emprego", "carreira", "profissão", "cargo", "promover", "demissão", "salário", "chefia"],
            // Adicione outros temas...
        };

        // Verifica cada tema
        for (const [tema, palavras] of Object.entries(temas)) {
            if (palavras.some(palavra => perguntaLower.includes(palavra))) {
                return tema;
            }
        }
        return "GERAL";
    }

    // Função para gerar uma resposta
    function gerarResposta(pergunta) {
        const tema = identificarTema(pergunta);
        const humor = Math.floor(Math.random() * 8); // 8 é o número de humores diferentes
        
        // Seleciona uma resposta aleatória para o tema e humor
        const respostasTema = respostas[tema] || respostas.GERAL;
        const humorNome = Object.keys(respostasTema)[humor % Object.keys(respostasTema).length];
        const respostasHumor = respostasTema[humorNome];
        
        const resposta = respostasHumor[Math.floor(Math.random() * respostasHumor.length)];
        return { resposta: resposta.resposta, explicacao: resposta.explicacao };
    }

    // Função para adicionar mensagem ao chat
    function adicionarMensagem(mensagem, tipo) {
        const messageDiv = document.createElement('div');
        messageDiv.className = `message ${tipo}`;
        messageDiv.textContent = mensagem;
        chatMessages.appendChild(messageDiv);
        chatMessages.scrollTop = chatMessages.scrollHeight;
    }

    // Evento de envio da mensagem
    enviarBtn.addEventListener('click', () => {
        const pergunta = perguntaInput.value.trim();
        if (!pergunta) return;

        // Adiciona a pergunta ao chat
        adicionarMensagem(pergunta, 'user');
        perguntaInput.value = '';

        // Simula um delay para a resposta
        setTimeout(() => {
            const resposta = gerarResposta(pergunta);
            adicionarMensagem(resposta.resposta, 'oracle');
            porqueBtn.style.display = 'block';
        }, 1000);
    });

    // Evento do botão "Por que?"
    porqueBtn.addEventListener('click', () => {
        const resposta = gerarResposta(perguntaInput.value);
        adicionarMensagem(resposta.explicacao, 'oracle');
        porqueBtn.style.display = 'none';
    });

    // Enter para enviar mensagem
    perguntaInput.addEventListener('keypress', (e) => {
        if (e.key === 'Enter' && !e.shiftKey) {
            e.preventDefault();
            enviarBtn.click();
        }
    });
});
