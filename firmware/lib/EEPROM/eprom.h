#ifndef _EEPROM_H_
#define _EEPROM_H_

void eepromWrite(String login, String senha);
String eepromReadlogin();
String eepromReadsenha();

#endif