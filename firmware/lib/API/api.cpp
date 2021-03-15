#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "rgb.h"
#include "dht.h"
#include "umidade_solo.h"


  // String montarPost(String umidadeAr, String temperatura, String umidadeSolo){
  //   String data = "{\"umidade_ar\":\"" + umidadeAr + "\",\"temperatura\":\"" + temperatura + "\",\"umidade_solo\":\"" + umidadeSolo + "\",\"planta\":\"" + 1 + "\"}";
  //   return data;
  // }

  String montarPost(String nomes[], String valor[], int size){
    String data;
    data += "{\"";
    for(int i = 0; i < size; i++){
      data += ""+nomes[i]+"\":\"" + valor[i] + "\",\"";
    }
    data += "\"}";
    return data;
  }

void EnviaRequest(String API){
  
  if(WiFi.status()== WL_CONNECTED){
    setColor("purple");
    dht DHT; 
    HTTPClient http;    //Declarar o objeto da classe HTTPClient
    float umidadeSolo = FazLeituraUmidade();
    DHT.read11(14); //LÊ AS INFORMAÇÕES DO SENSOR
    http.begin(API);      //Especifique o destino do request
    http.addHeader("Content-Type", "application/json");  //Especifica o tipo de conteúdo de header

    String nomes[] = {"ID", "Umidade do ar", "Umidade do solo", "Temperatura"};
    String valor[] = {"1", (String)DHT.humidity, (String)umidadeSolo, (String)DHT.temperature};
    String data = "{\"umidade_ar\":\"" + (String)DHT.humidity + "\",\"temperatura\":\"" + (String)DHT.temperature + "\",\"umidade_solo\":\"" + (String)umidadeSolo + "\",\"planta\":\"" + 1 + "\"}";
    Serial.println(data);
    
    
    int httpCode = http.POST(data);   //Envie o request
    String payload = http.getString();                  //Get the response payload

    
    Serial.println(httpCode);   //Print HTTP return code
    Serial.println(payload);    //Print request response payload
  
    http.end();  //Fechar conexão
    delay(500);
    setColor("green");       
    }       
  }

