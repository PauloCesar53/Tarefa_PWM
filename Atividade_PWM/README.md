# Tarefa_PWM
Repositório criado para versionamento da tarefa do dia 3 de fevereiro sobre PWM

## Descrição
 
O projeto  inicialmente mostra o Servomotor na posição de 180°, por cinco segundos,
posteriormente a posição é alterada para 90°, ficando por 5 segundos nessa posição, 
depois  a posição é alterada para 0°, ficando  por 5 segundos nessa posição. 
Após as etapas acima, o programa inicia o loop principal onde ocorre a mudança gradativa 
do ângulo, inicialmente de  0° a 180°, e ao atingir essa posição retorna gradativamente 
para 0°, repetindo este ciclo constantemente.  


## Compilação e Execução (instruções de uso )

1. Certifique-se de que o SDK do Raspberry Pi Pico está configurado no seu ambiente.
2. Compile o programa utilizando a extensão **Raspberry Pi Pico Project** no VS Code:
   - Abra o projeto no VS Code.

   - Vá até a extensão do **Raspberry pi pico project** e clique em  **import Project**, localize o ddiretório local onde esta o projeto e clique em  import (passo necessário para criar a pasta build). Depois **Compile Project**. Inicialmente o programa está configurado para Gpio referente ao servo motor, via simulação Wokwi.

3. Para utilizar na BitDogLag na GPIO 12 (LED azul), comente a linha 15 e utilize a linha 14 para substitui-lá. compile novamente o projeto,  Coloque a placa em modo BOOTSEL e copie o arquivo `Atividade_PWM.uf2`, que está na pasta build, para a BitDogLab conectado via USB.

---

## Demonstração no YouTube

Confira a demonstração completa deste projeto no YouTube: (https://www.youtube.com/watch?v=Wvw2_gG9tN4)

---

## Emulação com Wokwi

Para testar o programa sem hardware físico, você pode utilizar o **Wokwi** para emulação no VS Code:

1. Instale a extensão **Wokwi for VS Code**
3. Inicie a emulação:
   - Clique no arquivo `diagram.json` e inicie a emulação.
4. Teste o funcionamento do programa diretamente no ambiente emulado.

---

## Colaboradores
- [PauloCesar53 - Paulo César de Jesus Di Lauro ] (https://github.com/PauloCesar53)
