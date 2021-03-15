#include <Arduino.h>
#include <EEPROM.h> // Biblioteca da EEPROM

void eepromWrite(String login, String senha)
{
    int a = 2;
    int login_length = login.length();
    int senha_length = senha.length();

    Serial.println("\nLogin: ");
    for (int i = 0; i < login_length; i++)
    {
        EEPROM.write(a, login[i]);
        Serial.print(login[i]);
        a++;
    }

    Serial.println("\nSenha: ");
    for (int i = 0; i < senha_length; i++)
    {
        EEPROM.write(a, senha[i]);
        Serial.print(senha[i]);
        a++;
    }
    EEPROM.write(0, login_length);
    EEPROM.write(1, senha_length);
    EEPROM.commit();
}

String eepromReadlogin()
{
    int login_length = EEPROM.read(0);
    int senha_length = EEPROM.read(1);
    int a = 2;
    String login = "";
    String senha = "";

    for (int i = 0; i < login_length; i++)
    {
        login = login + char(EEPROM.read(a));
        a++;
    }

    for (int i = 0; i < senha_length; i++)
    {
        senha = senha + char(EEPROM.read(a));
        a++;
    }
    //  Serial.println("login: "+(String)login);
    //  Serial.println("senha: "+(String)senha);
    return login;
}

String eepromReadsenha()
{
    int login_length = EEPROM.read(0);
    int senha_length = EEPROM.read(1);
    int a = 2;
    String login = "";
    String senha = "";

    for (int i = 0; i < login_length; i++)
    {
        login = login + char(EEPROM.read(a));
        a++;
    }

    for (int i = 0; i < senha_length; i++)
    {
        senha = senha + char(EEPROM.read(a));
        a++;
    }
    //  Serial.println("login: "+(String)login);
    //  Serial.println("senha: "+(String)senha);
    return senha;
}