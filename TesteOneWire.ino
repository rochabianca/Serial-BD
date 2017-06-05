// Programa : Scan DS18B20
// Alterações : Arduino e Cia
// Este programa procura pelos sensores no circuito e mostra o valor 
// do endereço físico de cada sensor no Serial Monitor

#include <OneWire.h>

// Conecte o pino central dos sensores ao pino 10 do Arduino
OneWire  ds(2);  

void setup(void) 
{
  Serial.begin(115200);
  discoverOneWireDevices();
}

void discoverOneWireDevices(void) 
{
  byte i;
  byte present = 0;
  byte data[12];
  byte addr[8];

  Serial.print("Procurando dispositivos DS18B20...\n\r");

  while(ds.search(addr)) 
  {
    Serial.print("\n\rEncontrado sensor \'DS18B20\' com endereco:\n\r");
    for( i = 0; i < 8; i++) 
    {
      Serial.print("0x");
       if (addr[i] < 16) 
       {
        Serial.print('0');

       }
      Serial.print(addr[i], HEX);

       if (i < 7) 
       {
        Serial.print(", ");
       }

    }

    if ( OneWire::crc8( addr, 7) != addr[7]) 
    {
        Serial.print("CRC nao e valido!\n");
        return;
    }
  }
  Serial.print("\n\r\n\rFinal da verificacao.\r\n");
  ds.reset_search();
  return;
}

void loop(void) 
{
  // Loop Vazio
} 
