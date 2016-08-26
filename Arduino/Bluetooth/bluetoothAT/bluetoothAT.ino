/* Program to test AT commands on HC-05 module: 
   - Sets "Key" pin on HC-05 HIGH to enable command mode
   - The HC-05 LED Blink SLOWLY: 2 seconds ON/OFF 
   Connections:  GND to HC-05 GND, Pin 2 to HC-05 TXD, 
   Pin 3 to HC-05 RXD, Pin 4 to HC-05 KEY, 
   Pin 5 to HC-05 VCC for power control
*/
/* Copyright (C) <2016>  <Chaitanya Baweja> <http://www.gnu.org/licenses/>
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/

#include <SoftwareSerial.h>  
#define ARDUINO_RXD 2
#define ARDUINO_TXD 3
#define KEY        4

SoftwareSerial BTSerial(ARDUINO_RXD, ARDUINO_TXD); // RX | TX

void setup()   
{
  pinMode(KEY, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(KEY, HIGH);  // Set command mode when powering up
  pinMode(5,OUTPUT);
  Serial.begin(9600);
  delay(2000);
  digitalWrite(5,HIGH);   
  Serial.println("Enter AT commands: ");
  BTSerial.begin(38400);  // HC-05 default speed in AT command mode

}


void loop()   
{
  // READ from HC-05 and WRITE to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // READ Arduino Serial Monitor and WRITE to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());

}
