## ENVIAR SERIAL PARA BANCO DE DADOS

Projeto feito com o objetivo de pegar dados de um sensor de temperatura(no caso foi utilizado um sensor DSB20 mas é para funcionar com qualquer sensor com o barramento OneWire) e envia-los a um banco de dados (nesse caso, foi utilizado o MySQL) através de um programa em Python.

## Instruções

Executar o arquivo TesteOneWire com o sensor já conectado corretamente ao hardware (nesse exemplo foi utilizado o módulo NodeMCU então a porta 2 equivale a porta D4) e copiar o código
resultante dentro da variável insideThermometer no arquivo serial-banco.ino. A partir daí executar esse arquivo no dispositivo e executar o arquivo python (relembrando que o servidor MySQL deverá estar ativo para que a transferencia possa ser concluida)

## Banco de dados
banco: arduino
tabela: sinais
colunas:
    sin_id - int(11) not null auto_increment
    sin_data - datetime not null current_timestamp
    sin_temp - varchar(255) uft8_general_ci not null