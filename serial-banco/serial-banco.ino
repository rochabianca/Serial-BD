#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress insideThermometer = { 0x28, 0x6B, 0xEE, 0xBA, 0x03, 0x00, 0x00, 0x33 };

String sinais; // Variável usada para enviar os sinais
float temperatura;
void setup() {
  Serial.begin(115200); //Inicia comunicação serial
  sensors.begin();
  sensors.setResolution(insideThermometer, 10);    
  delay(600); // Aguarda o sensor armar           
}
 
void loop() {

  sensors.requestTemperatures();
  temperatura = sensors.getTempC(insideThermometer);
  //float t = 23.4, h = 24.5;
  sinais = String(temperatura);
  //sinais = "28|24";
  Serial.println(sinais);
  delay(6000); //Aguarda 30 segundos
 
}
