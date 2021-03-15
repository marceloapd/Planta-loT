#include <Arduino.h>

void setColor(String cor)
{
	if (cor.equals("red"))
	{
		digitalWrite(5, LOW);
		digitalWrite(16, HIGH);
		digitalWrite(4, HIGH);
	}
	else if (cor.equals("green"))
	{
		digitalWrite(5, HIGH);
		digitalWrite(16, LOW);
		digitalWrite(4, HIGH);
	}
	else if (cor.equals("blue"))
	{
		digitalWrite(5, HIGH);
		digitalWrite(16, HIGH);
		digitalWrite(4, LOW);
	}
	else if (cor.equals("purple"))
	{
		digitalWrite(5, LOW);
		digitalWrite(16, HIGH);
		digitalWrite(4, LOW);
	}
	else if (cor.equals("yellow"))
	{
		digitalWrite(5, LOW);
		digitalWrite(16, LOW);
		digitalWrite(4, HIGH);
	}
	else if (cor.equals("ciano"))
	{
		digitalWrite(5, LOW);
		digitalWrite(16, HIGH);
		digitalWrite(4, LOW);
	}
	else if (cor.equals("white"))
	{
		digitalWrite(5, LOW);
		digitalWrite(16, LOW);
		digitalWrite(4, LOW);
	}
	else if (cor.equals("off"))
	{
		digitalWrite(5, HIGH);
		digitalWrite(16, HIGH);
		digitalWrite(4, HIGH);
	}
}

void piscarLed(String cor)
{
	setColor(cor);
	delay(500);
	setColor("off");
	delay(500);
}

void piscarLedWifi(int loop)
{
	for (int i = 0; i < loop; i++)
	{
		setColor("blue");
		delay(500);
		setColor("off");
		delay(500);
	}
}