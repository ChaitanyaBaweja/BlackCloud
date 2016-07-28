/*
 This program reads data from two MQ135 sensors, one module
 and one our own built module and then stores the average 
 100 readings over 5 seconds in an SD Card.
 Also a timestamp is added using the delay fuction
 This will be used for evaluation ad testing purposes	
 The circuit:
 * SD card attached to SPI bus as follows:
 ** UNO:  MOSI - pin 11, MISO - pin 12, CLK - pin 13, CS - pin 10
  and pin #10 (SS) must be an output
*/
/* Copyright (C) <2016>  <Chaitanya Baweja> <http://www.gnu.org/licenses/>
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/

#include <SPI.h>
#include <SD.h>

int Count=1;
float Average = 0.0, Average1 = 0.0;
int integerAverage, integerAverage1;
const int chipSelect = 10;
int date, hours,minutes, seconds ;
File dataFile;

void setup()
{ Serial.begin(9600);
  Serial.print("Initializing SD card...");
  pinMode(SS, OUTPUT);
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1) ;
  }
  Serial.println("card initialized.");
  dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (! dataFile) {
    Serial.println("error opening datalog.txt");
    while (1) ;
  }
  date=0;
  hours=0;
  minutes=0;
  seconds=0;
}

void loop()
{ String dataString = "";             //makes it blank 
  int AnalogVoltage=analogRead(A0);   //reading module
  int AnalogVoltage1=analogRead(A1);  // reading custom PCB
  if(Count<=100)
  { Average=Average+(AnalogVoltage/(100.0));  //adding next reading to average
    Average1=Average1+(AnalogVoltage1/(100.0));
  }
  else
  { Count=0;
  }
  if(Count==0)
  { seconds+=5;          //after 5 seconds
    if(seconds==60)      //after 1 minute
    { seconds=0;
      minutes+=1;
      if(minutes==60)    //after 1 hour
      { minutes=0;
      hours+=1;
        if(hours==24)    //after 1 day
        { hours=0;
        date+=1;
        }
      }
    }
    integerAverage=(int)Average;                //type casting to integer
    integerAverage1=(int)Average1;
    dataString+= String(date);
    dataString+= (" day ");
    dataString+= String(hours);
    dataString+= (":");
    dataString+= String(minutes);
    dataString+= String(":");
    dataString+= String(seconds);
    dataString+=(" Module: "); 
    dataString += String(integerAverage);
    dataString += (" Our: ");
    dataString += String(integerAverage1);
    Average=(AnalogVoltage/(100.0));      //average set to initial reading
    Average1=(AnalogVoltage1/(100.0));
    Count=1;
    dataFile.println(dataString);
    // print to the serial port too:
    Serial.println(dataString);
  }
  Count++;
  dataFile.flush();
  delay(50);
}









