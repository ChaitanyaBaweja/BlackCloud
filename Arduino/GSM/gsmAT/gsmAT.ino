/* < Program to send AT commands to GSM Module >
 
 * Copyright (C) <2016>  <Chaitanya Baweja> <http://www.gnu.org/licenses/>
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/

#include <SoftwareSerial.h>
#define RX 2 
#define TX 3 

SoftwareSerial ss = SoftwareSerial(TX, RX); //initialize software serial
char inChar = 0;
void setup() {
    
    Serial.begin(9600);
    Serial.println("Serial Ready");
    ss.begin(9600);
    Serial.println("Software Serial Ready");
}
void loop() {
    if (ss.available()){
        inChar = ss.read();
        Serial.write(inChar);
        delay(20);
    }
    if (Serial.available()>0){
        ss.write(Serial.read());
    }
}
