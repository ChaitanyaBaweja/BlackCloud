/* < Program to test RGB LED Strip
 
 * A RGB LED was added to an arduino UNO with the sensor to indicate level of pollution >
 
 * Copyright (C) <2016>  <Chaitanya Baweja> <http://www.gnu.org/licenses/>
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/
void setup() {
  // put your setup code here, to run once:
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(10, HIGH);
delay(3000);
digitalWrite(10, LOW);
digitalWrite(9, HIGH);
delay(3000);
digitalWrite(9, LOW);
digitalWrite(8, HIGH);
delay(3000);
digitalWrite(8, LOW);
}
