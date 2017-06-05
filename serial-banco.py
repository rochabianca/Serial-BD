#!/usr/bin/python
# -*- coding: iso-8859-1 -*-
import serial
import mysql.connector
comport = serial.Serial('COM3', 115200) #Porta onde está conectado o arduino e velocidade.
print('Serial Iniciada...')             #ATENÇÃO: se o serial monitor estiver sendo usado esse
                                        #código retornará um erro, pois a porta estará em uso

cnx = mysql.connector.connect(user='root', password='', host='localhost', database='freqcardiaca')
cursor = cnx.cursor() 
add_sinais = (
  "INSERT INTO `freqcardiaca`.`dados` (`id`, `data`, `frequencia`)" 
  "VALUES (NULL, CURRENT_TIMESTAMP, %(temp)s);"
)

while (True):
    serialValue = comport.readline()
    data_sinais = serialValue
    print(data_sinais)
    cursor.execute(add_sinais,{ 'temp': data_sinais })
    cnx.commit()
    
cursor.close()
cnx.close()
comport.close()