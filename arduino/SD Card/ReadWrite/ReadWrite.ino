/*
  SD card read/write
  Program to read and write data to and from an SD card file 	
  The circuit:
  MOSI - pin 11, MISO - pin 12, CLK - pin 13, CS - pin 10
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

File myFile;
const int chipSelect = 10;

void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  pinMode(SS, OUTPUT);
  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  myFile = SD.open("test.txt", FILE_WRITE);
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
	// close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  
  // re-open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");
  // read from the file until there's nothing else in it:
  while (myFile.available()) {
  Serial.write(myFile.read());
  }
  // close the file:
  myFile.close();
  } else {
  // if the file didn't open, print an error:
  Serial.println("error opening test.txt");
  }
}
void loop()
{
	
}


