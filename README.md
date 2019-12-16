# DS3231
Ejemplo de una alarma utilizando el modulo [**RTC DS3231.**](https://www.taloselectronics.com/products/reloj-de-tiempo-real-rtc-ds3231-para-raspberry-pi:// "RTC DS3231")
Las librerias necesarias se encuentran en la carpeta librerias, para cambiar la hora en la que se dispare la alarma basta con cambiar las variables** hora** y **minutos** que estan en un formato de 24 hrs.
    
    RTC_DS3231 RTC;
    
    const int hora=13;
    const int minutos=40;