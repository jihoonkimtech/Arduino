#include <SoftwareSerial.h>

SoftwareSerial hc06(7,6);

#define SPEED 115200

void setup(){
  //Initialize Serial Monitor
  Serial.begin(SPEED);
  //Initialize Bluetooth Serial Port
  hc06.begin(SPEED);
}

void loop(){
  //Write data from HC06 to Serial Monitor
  if (hc06.available()){
    Serial.write(hc06.read());
  }
  
  //Write from Serial Monitor to HC06
  if (Serial.available()){
    hc06.write(Serial.read());
  }  
}
