/*
 *  Libreria RTCLIB
 * 
 */
#include <Wire.h>
#include <SPI.h> // not used here, but needed to prevent a RTClib compile error
#include <RTClib.h>

RTC_DS3231 RTC;

const int hora=13;
const int minutos=40;

void setup()
{
    Serial.begin(9600);
    Wire.begin();
    RTC.begin();

    RTC.adjust(DateTime(__DATE__, __TIME__));//Ajustar hora comentar despues de subir el codigo
    if (!RTC.isrunning())
    {
        Serial.println("RTC is NOT running!");
        // following line sets the RTC to the date & time this sketch was compiled
        RTC.adjust(DateTime(__DATE__, __TIME__));
    }
    DateTime now = RTC.now();
    RTC.setAlarm1Simple(hora, minutos);
    RTC.turnOnAlarm(1);
    if (RTC.checkAlarmEnabled(1))
    {
        Serial.println("Alarma activada");
    }
}

void loop()
{
    DateTime now = RTC.now();
    printDate(now);
    

    if (RTC.checkIfAlarm(1))
    {
        Serial.println("Despierta es hora");
    }
    Serial.println();
    delay(1000);
}
void printDate(DateTime now)
{
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
}