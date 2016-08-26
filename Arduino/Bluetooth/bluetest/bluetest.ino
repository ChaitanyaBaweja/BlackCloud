/* Program to send values to android device using HC-05 module: 
   - The HC-05 LED Blink SLOWLY: 2 seconds ON/OFF 
   Connections:  GND to HC-05 GND, Pin 10 to HC-05 TXD, 
   Pin 11 to HC-05 RXD, Pin 5V to HC-05 VCC
*/
/* Copyright (C) <2016>  <Chaitanya Baweja> <http://www.gnu.org/licenses/>
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/


#include <SoftwareSerial.h>// import the serial library
SoftwareSerial CAH(10, 11); // RX, TX

void setup() {
  CAH.begin(9600); //setting Baud Rate of Bluetooth to 9600
  CAH.print("#10 10 10 10 10 10 10 10 10 10");//sending this code as needed for app
}

void loop() {
  delay(10000);//delay for 10sec
  CAH.print("#10 10 10 10 10 10 10 10 10 10");
}

