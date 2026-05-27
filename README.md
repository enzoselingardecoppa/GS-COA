# GS-COA

# Global Solution 2026 - Mission Control AI

Repositório dedicado ao projeto de monitoramento de cápsula espacial desenvolvido para a Global Solution da FIAP (Ciência da Computação). O circuito utiliza um Arduino para ler sensores ambientais, tratar alertas de criticidade e exibir os status operacionais em um display local.

## Links do Projeto
* **Tinkercad:** [Insira aqui o link de convite que você copiou]
* **Vídeo de Demonstração:** https://youtu.be/qKu91US929c

## Componentes Utilizados
* 1x Arduino Uno R3
* 1x Sensor de Temperatura TMP36
* 1x Sensor de Luminosidade LDR
* 1x Display LCD 16x2
* 1x Push Button (Simulação de Turbulência via INPUT_PULLUP)
* 3x LEDs (Verde, Amarelo e Vermelho)
* Resistores de 220Ω e 10kΩ
* 1x Potenciômetro de 10kΩ

## Funcionamento do Código
O algoritmo realiza a leitura cíclica dos sensores analógicos e valida as seguintes regras de negócio:
* **Temperatura:** Aciona o LED correspondente (Verde < 35°C, Amarelo entre 35°C e 50°C, Vermelho > 50°C) e atualiza o status no LCD.
* **Luminosidade:** Identifica variações de radiação externa (Low Light, Light OK e Solar Alert).
* **Vibração/Impacto:** O botão interrompe o fluxo normal para estampar o alerta de "TURBULENCE" na tela enquanto estiver acionado.
* **Métricas extras:** Simulação interna de decaimento de bateria (Energia) e status de rede (Comunicação) para conformidade com o enunciado.
