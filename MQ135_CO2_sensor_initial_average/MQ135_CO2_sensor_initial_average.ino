/* < Program to test the MQ135 sensor.
 * The sensor module was kept on burn time for two days and then these values recorded
 * It receives Analog Voltage from the sensor on A0 and 
   then takes the average for smoothing readings.
 * The average of 100 values in 5 seconds and is then converted to integer as floating analogread makes no sense.
 * A RGB LED was added to an arduino UNO with the sensor to indicate level of pollution >
 
 * Copyright (C) <2016>  <Chaitanya Baweja> <http://www.gnu.org/licenses/>
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/
#define Green 10
#define Red 9
#define Blue 8
int Count=1;
float Average = 0.0;
int integerAverage;
void setup() {
  Serial.begin(9600);
  Serial.println("Test run MQ135");  //set BaudRate to 9600
  pinMode(Green, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Blue, OUTPUT);
  digitalWrite(Green, HIGH);
  digitalWrite(Red, LOW);
  digitalWrite(Blue, LOW);
}
void loop() {
  int AnalogVoltage=analogRead(A0);
  if(Count<=100)
  { Average=Average+(AnalogVoltage/(100.0));  //adding next reading to average
  }
  else
  { Count=0;
  }
  if(Count==0)
  { Serial.print("Analog Voltage Mean Output:");
    integerAverage=(int)Average;                //type casting to integer
    Serial.println(integerAverage);
    if(Average<250)
    {  digitalWrite(Green, HIGH);
       digitalWrite(Red, LOW);
       digitalWrite(Blue, LOW);}
    else if(Average<300)
    {  digitalWrite(Green, LOW);
       digitalWrite(Red, LOW);
       digitalWrite(Blue, HIGH);
    }
    else
    {  digitalWrite(Green, LOW);
       digitalWrite(Red, HIGH);
       digitalWrite(Blue, LOW);
    }
    Average=(AnalogVoltage/(100.0));      //average set to initial reading
    Count=1;
  }
   
  Count++;
  delay(50);  //delay reading by 50ms
}
