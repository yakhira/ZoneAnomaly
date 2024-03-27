#include <Arduino.h>
#include "utils/uart.h"

#define SOUND PB0
#define PIR PB1
#define BUZZER PB2

#define DELAY_TIME 60000

void collapse()
{
	for (int j =  0; j < 1000; j++) {
		for (int i = 0; i < 25; i++){
			digitalWrite(BUZZER, HIGH);
			delayMicroseconds(750);
			digitalWrite(BUZZER, LOW);
			delayMicroseconds(750);
		}

		delay(50);

		for (int i = 0; i < 25; i++){
			digitalWrite(BUZZER, HIGH);
			delayMicroseconds(500);
			digitalWrite(BUZZER, LOW);
			delayMicroseconds(500);
		}
		delay(100);
	}
}

void setup(void)
{
	uart_puts("ZoneAnomaly started!");

	pinMode(SOUND, INPUT);
	pinMode(PIR, INPUT);
	pinMode(BUZZER, OUTPUT);

	digitalWrite(BUZZER, LOW);
	delay(DELAY_TIME);

	uart_puts("Activated!\r\n");
}

void loop()
{
	if ((digitalRead(SOUND) == HIGH) || (digitalRead(PIR) == HIGH)){
		uart_puts("Detected!\r\n");
		collapse(); 
		uart_puts("Activated!\r\n");
	}
}