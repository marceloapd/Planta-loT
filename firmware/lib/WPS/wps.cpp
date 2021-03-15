#include <Arduino.h>
#include "rgb.h"
#include <ESP8266WiFi.h> // Biblioteca de WiFi
#include "eprom.h"

void piscaled(){
  setColor("blue");
  delay(500);
  setColor("blue");
  delay(500);
}

bool WPS(){
    Serial.println("WPS config começou");
    WiFi.mode(WIFI_STA);
    delay(1000);
    WiFi.begin("foobar", "");

    while (WiFi.status() == WL_DISCONNECTED)
    {
        piscarLed("blue");
        Serial.print(WiFi.status());
    }   
    setColor("red");
    bool wpsSuccess = WiFi.beginWPSConfig();
    
    if (wpsSuccess)
    {
        //Sempre significa sucesso: - / no caso de um tempo limite, temos um SSID vazio
        String newSSID = WiFi.SSID();
        String newSenha = WiFi.psk();
        
        if (newSSID.length() > 0)
        {
            setColor("green");
            // WPSConfig has already connected in STA mode successfully to the new station.
            Serial.printf("WPS concluído. Conectado com sucesso ao SSID '%s' '%s'", newSSID.c_str(), newSenha.c_str());
            // save to config and use next time or just use - WiFi.begin(WiFi.SSID().c_str(),WiFi.psk().c_str());
            //qConfig.wifiSSID = newSSID;
            //qConfig.wifiPWD = WiFi.psk();
            //saveConfig();
            eepromWrite(newSSID, newSenha);
        }
        else
        {
            Serial.printf("Falha ao se conectar ao WPS, tente novamente !");
            wpsSuccess = false;
        }
        return wpsSuccess;
    }
    Serial.println("\nConectado\n");

}
