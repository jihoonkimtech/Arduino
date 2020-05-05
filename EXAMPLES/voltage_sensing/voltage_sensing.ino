#define R1 30000.0
#define R2 7500.0
#define ANALOG_MAX 1024.0
#define MUITPLE 5.0
#define SENSORPIN A0

#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x3F,16,2);

float voltageRead(int pin);

void setup() {
  pinMode(SENSORPIN, INPUT);
  //lcd.init();  
  //lcd.backlight();  
  Serial.begin(9600);
  Serial.println("VOLTAGE DETEC");
  Serial.print(" V");
  Serial.println();
}

void loop() {
  Serial.print("read voltage value : ");
  float v = voltageRead(SENSORPIN);
  Serial.print(v);
  Serial.println(" V");
  Serial.println("");
  //lcd.clear();
  //lcd.home(); lcd.print(v); lcd.print(" V ");
  delay(1000);
}

float voltageRead(int pin){
  float analogIn = analogRead(pin);
  float volt1 = (analogIn * MUITPLE) / ANALOG_MAX;
  float volt2 = volt1 / (R2/(R1+R2));
  return volt2;
}
