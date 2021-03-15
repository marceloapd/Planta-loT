#include <Arduino.h>
#include <EEPROM.h>            // Biblioteca da EEPROM
#include <ESP8266HTTPClient.h> // Biblioteca de request
#include "ESP8266HTTPClient.h"
#include <ESP8266WiFi.h> // Biblioteca de WiFi
#include "rgb.h"
#include "wps.h"
#include "eprom.h"
#include "wifi.h"
#include "dht.h"
#include "api.h"
#include "umidade_solo.h"
#include "thingspeak.h"
#include "tweet.h"

#define Botao D3 // Botão flash do esp GPIO 0

int red = 5;    //PINO DIGITAL EM QUE O TERMINAL 'R' ESTÁ CONECTADO
int green = 16; //PINO DIGITAL EM QUE O TERMINAL 'G' ESTÁ CONECTADO
int blue = 4;   //PINO DIGITAL EM QUE O TERMINAL 'B' ESTÁ CONECTADO
const int pinoDHT11 = 14;
float umidadeSolo = FazLeituraUmidade();
void setup()
{
  EEPROM.begin(512);
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
  VerificaConexao();
}

void loop()
{
  // EnviaRequest("http://c6c3455fb119.ngrok.io/info/");
  enviarDadosThingSpeak();
  // tweet("Teste02");
  delay(30000);
  
  if (digitalRead(Botao) == LOW)
  {
    WiFi.disconnect();
    WPS(); // Chama função para conexão do WiFi via WPS
  }

  
}
  