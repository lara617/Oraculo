document.addEventListener('DOMContentLoaded', () => {
    const perguntaInput = document.getElementById('pergunta');
    const enviarBtn = document.getElementById('enviar');
    const porqueBtn = document.getElementById('porque');
    const chatMessages = document.getElementById('chatMessages');
    const explicacao = document.getElementById('explicacao');
    const bolaCristal = document.querySelector('.bola-cristal');

    // Adiciona animação de entrada para a bola de cristal
    setTimeout(() => {
        bolaCristal.classList.add('animate__animated', 'animate__pulse');
    }, 1000);

    // Adiciona animação de digitação para o placeholder
    const placeholderText = 'Faça sua pergunta ao Oráculo... 🌟';
    let placeholderIndex = 0;
    perguntaInput.placeholder = '';

    function typePlaceholder() {
        if (placeholderIndex < placeholderText.length) {
            perguntaInput.placeholder += placeholderText.charAt(placeholderIndex);
            placeholderIndex++;
            setTimeout(typePlaceholder, 100);
        }
    }

    setTimeout(typePlaceholder, 1500);

    // Adiciona efeito de brilho ao passar o mouse
    bolaCristal.addEventListener('mouseenter', () => {
        bolaCristal.style.boxShadow = '0 0 50px rgba(0, 255, 0, 0.5)';
    });

    bolaCristal.addEventListener('mouseleave', () => {
        bolaCristal.style.boxShadow = '0 0 30px rgba(0, 255, 0, 0.3)';
    });

    // Adiciona animação ao enviar mensagem
    enviarBtn.addEventListener('click', () => {
        const pergunta = perguntaInput.value.trim();
        if (!pergunta) return;

        // Adiciona a pergunta ao chat com animação
        const messageDiv = document.createElement('div');
        messageDiv.className = 'message user animate__animated animate__fadeInLeft';
        messageDiv.textContent = pergunta;
        chatMessages.appendChild(messageDiv);
        perguntaInput.value = '';

        // Simula um delay para a resposta
        setTimeout(() => {
            const resposta = gerarResposta(pergunta);
            const respostaDiv = document.createElement('div');
            respostaDiv.className = 'message oracle animate__animated animate__fadeInRight';
            respostaDiv.textContent = resposta.resposta;
            chatMessages.appendChild(respostaDiv);
            chatMessages.scrollTop = chatMessages.scrollHeight;
            explicacao.classList.add('active');
        }, 1000);
    });

    // Evento do botão "Por que?"
    porqueBtn.addEventListener('click', () => {
        const resposta = gerarResposta(perguntaInput.value);
        const explicacaoDiv = document.createElement('div');
        explicacaoDiv.className = 'message oracle animate__animated animate__fadeInRight';
        explicacaoDiv.textContent = resposta.explicacao;
        chatMessages.appendChild(explicacaoDiv);
        chatMessages.scrollTop = chatMessages.scrollHeight;
        explicacao.classList.remove('active');
    });

    // Adiciona animação de digitação para as respostas
    function adicionarMensagem(mensagem, tipo) {
        const messageDiv = document.createElement('div');
        messageDiv.className = `message ${tipo}`;
        
        // Adiciona animação de digitação
        let index = 0;
        const text = mensagem;
        
        function typeText() {
            if (index < text.length) {
                messageDiv.textContent += text.charAt(index);
                index++;
                setTimeout(typeText, 50);
            }
        }
        
        typeText();
        chatMessages.appendChild(messageDiv);
        chatMessages.scrollTop = chatMessages.scrollHeight;
    }

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
            FAMÍLIA: ["família", "pai", "mãe", "irmão", "irmã", "filho", "filha", "parente", "relação familiar"],
            SAÚDE: ["saúde", "doença", "médico", "hospital", "cura", "bem-estar", "exame", "diagnóstico"],
            DINHEIRO: ["dinheiro", "finanças", "investimento", "economia", "gastos", "contas", "dívida", "herança"],
            VIAGEM: ["viagem", "viagem", "destino", "viajar", "férias", "turismo", "rota", "jornada"],
            ESTUDOS: ["estudo", "faculdade", "curso", "aprendizado", "exame", "prova", "disciplina", "aula"],
            AMIZADE: ["amizade", "amigo", "companheiro", "confiança", "solidariedade", "apoio", "companhia"],
            ESPIRITUALIDADE: ["espiritualidade", "meditação", "paz", "harmonia", "energia", "aura", "chakra"],
            GERAL: ["vida", "futuro", "destino", "sorte", "azar", "oportunidade", "sorte", "azar"]
        };

        // Criar estrelas
        const starsContainer = document.querySelector('.stars');
        for (let i = 1; i <= 50; i++) {
            const star = document.createElement('div');
            star.className = `star-${i}`;
            starsContainer.appendChild(star);
        }

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
