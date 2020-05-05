#include <DHT11.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
int SensorPin = 2;
DHT11 dht11(SensorPin);

byte charTemp[8] = {
        B01110,
        B01010,
        B01110,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000
};

byte onchar[8] = {
        B01110,
        B10001,
        B01110,
        B00100,
        B11111,
        B00000,
        B10000,
        B11111
};

byte dochar[8] = {
        B11111,
        B10000,
        B10000,
        B11111,
        B00000,
        B00100,
        B00100,
        B11111
};

byte supchar[8] = {
        B00100,
        B01010,
        B10001,
        B00000,
        B11111,
        B00000,
        B10001,
        B11111
};


void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.begin(16,2);
  lcd.backlight();
  lcd.createChar(0, charTemp);
  lcd.createChar(1, onchar);
  lcd.createChar(2, dochar);
  lcd.createChar(3, supchar);
  lcd.setCursor(0,0);
  lcd.print("Hello, World!");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("I'm Ready!");
  delay(1000);
  lcd.clear();

}

void loop() {
  float temp, humi;
  dht11.read(humi, temp);;
  Serial.println(temp);
  Serial.println(humi);
  lcd.setCursor(0,0);
  lcd.write(3);
  lcd.write(2);
  lcd.print(" : ");
  lcd.print(temp);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.write(1);
  lcd.write(2);
  lcd.print(" : ");
  lcd.print(humi);
  lcd.write(0);
  lcd.print("C");
  delay(1000);

}
