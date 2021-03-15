#include <Arduino.h>

float FazLeituraUmidade()
{
    int ValorADC;
    float UmidadePercentual;

    ValorADC = analogRead(0); //1024 -> 3,3V
    UmidadePercentual = 100 * ((1024 - (float)ValorADC) / 674);

  UmidadePercentual = 100 * ((980 - (float)ValorADC) / 710);

  if (ValorADC <= 270)
  {
    UmidadePercentual = 100.0;
  }else if (ValorADC >=1000){
    UmidadePercentual = 0;
  }

    return UmidadePercentual;
}
