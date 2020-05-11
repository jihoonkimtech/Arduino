#include <Wire.h>
#include <LiquidCrystal_I2C.h> //lcd
int trigPin = 13;
int echoPin = 12;
int trig = 9;
int echo = 8;
LiquidCrystal_I2C lcd(0x3F, 16, 2);
//int irSensor_Pin = A0;
int distance = 0;
int peopleVal = 0;
int buttonPin = 2; 
int buttonTwoPin = 4;
//int irSensorPin = 3;
int sensorVal;
int val;
boolean INdetection = 0;
boolean OUTdetection = 0;

byte mong[8] = {
        B11111,
        B10001,
        B11111,
        B00100,
        B11111,
        B01110,
        B10001,
        B01110
};
byte sil[8] = {
        B01001,
        B10101,
        B10101,
        B11111,
        B00001,
        B11111,
        B10000,
        B11111
};
byte hak[8] = {
        B01010,
        B11110,
        B01011,
        B10110,
        B01010,
        B11110,
        B00010,
        B00010
};
byte gyo[8] = {
        B11111,
        B00001,
        B00001,
        B00001,
        B01011,
        B01010,
        B01010,
        B11111
};
byte bang[8] = {
        B10110,
        B11111,
        B10110,
        B11110,
        B00000,
        B01110,
        B10001,
        B01110
};
byte moon[8] = {
        B11111,
        B10001,
        B11111,
        B00000,
        B11111,
        B00100,
        B10000,
        B11111
};
byte ja[8] = {
        B11110,
        B01010,
        B01010,
        B01010,
        B10111,
        B10110,
        B10110,
        B10110
};
byte su[8] = {
        B00100,
        B00100,
        B01010,
        B10001,
        B00000,
        B11111,
        B00100,
        B00100
};
byte charOne[8] = {
        B01000,
        B11100,
        B01001,
        B10101,
        B00001,
        B01001,
        B01001,
        B11111
};
byte charTwo[8] = {
        B00101,
        B11101,
        B10101,
        B10111,
        B10101,
        B10101,
        B11101,
        B00101
};


void setup() {
  Serial.begin(9600);
  //pinMode (irSensor_Pin, INPUT);
  //pinMode (irSensorPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonTwoPin, INPUT_PULLUP);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  lcd.init();
  lcd.createChar(0, mong);
  lcd.createChar(1, sil);
  lcd.createChar(2, hak);
  lcd.createChar(3, gyo);
  lcd.createChar(4, bang);
  lcd.createChar(5, moon);
  lcd.createChar(6, ja);
  lcd.createChar(7, su);
  //lcd.createChar(8, charOne);
  //lcd.createChar(9, charTwo);
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.write(0); lcd.write(1); lcd.write(2); lcd.write(3);
  lcd.print(" ");
  lcd.write(4); lcd.write(5); lcd.write(6); lcd.write(7);
  lcd.print(" ");
  lcd.print("Check");
  lcd.setCursor(0,1);
  lcd.write(4); lcd.write(5); lcd.write(6); lcd.write(7);
  lcd.print(" : ");
  
}

void loop() {
  while (true)
  {
  //int data = analogRead(irSensor_Pin);
  //int volt = map(data, 0, 1023, 0, 5000);
  //distance = (21.61/(volt-0.1696))*1000;
  //sensorVal = digitalRead(irSensorPin);
  long duration, distanceVal;
     digitalWrite(trigPin ,LOW);
     delayMicroseconds(2);
     digitalWrite(trigPin ,HIGH);
     delayMicroseconds(10);
     digitalWrite(trigPin ,LOW);
     duration = pulseIn(echoPin, HIGH);
     distanceVal = (duration/2)/29.1;
   long durationTwo, distanceValTwo;
     digitalWrite(trig ,LOW);
     delayMicroseconds(2);
     digitalWrite(trig, HIGH);
     delayMicroseconds(10);
     digitalWrite(trig ,LOW);
     durationTwo = pulseIn(echo, HIGH);
     distanceValTwo = (durationTwo/2)/29.1;
  Serial.println(sensorVal);
  Serial.println(distance);
  Serial.println(INdetection);
  Serial.println(OUTdetection);
  INdetection = 0;
  OUTdetection = 0;
  if(digitalRead(buttonTwoPin) == LOW)
  {
    lcd.setCursor(0,1);
    lcd.print("MAX ");
    lcd.write(4); lcd.write(5); lcd.write(6); lcd.write(7);
    lcd.print(" : ");
    lcd.setCursor(12,1);
    lcd.print(val);
    lcd.setCursor(10,1);
    delay (3000);
    lcd.setCursor(0,1);
    lcd.print("                ");
    delay(100);
    lcd.setCursor(0,1);
    lcd.write(4); lcd.write(5); lcd.write(6); lcd.write(7);
    lcd.print(" : ");
  }
   if(digitalRead(buttonPin) == LOW){         
    lcd.setCursor(7,1);
    lcd.print("Reset."); 
    delay(500);
    lcd.setCursor(7,1);
    lcd.print("Reset.."); 
    delay(500);
    lcd.setCursor(7,1);
    lcd.print("Reset..."); 
    delay(500);
    lcd.setCursor(7,1);
    lcd.print("        ");
    val = 0;
    peopleVal = 0;
  }
  if(distanceVal > 0 && distanceVal <= 50)
  { 
   delay(700);
   //int data = analogRead(irSensor_Pin);
   //int volt = map(data, 0, 1023, 0, 5000);
   //distance = (21.61/(volt-0.1696))*1000;
   long durationTwo, distanceValTwo;
     digitalWrite(trig ,LOW);
     delayMicroseconds(2);
     digitalWrite(trig,HIGH);
     delayMicroseconds(10);
     digitalWrite(trig ,LOW);
     durationTwo = pulseIn(echo, HIGH);
     distanceValTwo = (durationTwo/2)/29.1;
   Serial.println("detecting");
     if(distanceValTwo > 0 && distanceValTwo <= 50)
     {
       INdetection = 1;
       Serial.println("detect");
       delay(500);
     }
  }
   else if(distanceValTwo > 0 && distanceValTwo <= 50)
   { 
   delay(700);
     //sensorVal = digitalRead(irSensorPin);
     long duration, distanceVal;
     digitalWrite(trigPin ,LOW);
     delayMicroseconds(2);
     digitalWrite(trigPin ,HIGH);
     delayMicroseconds(10);
     digitalWrite(trigPin,LOW);
     duration = pulseIn(echoPin, HIGH);
     distanceVal = (duration/2)/29.1;
   Serial.println("detecting OUT");
     if(distanceVal > 0 && distanceVal <= 50)
     {
       OUTdetection = 1;
       Serial.println("detect OUT");
       delay(500);
     }
   }
     else
     {
       INdetection = 0;
       OUTdetection = 0;
       Serial.println("NOPE IN/OUT");
     } 
   if(INdetection == 1)
   {
     Serial.println("detect ++");
       peopleVal++;
       val++;
       delay(1000);
   }
   else if(OUTdetection == 1)
   {
     Serial.println("detect --");
       peopleVal--;
       delay(1000);
   } 
   else
   {
     Serial.println("Not");
   }
   Serial.println("ddddddd");
   Serial.println(INdetection);
  Serial.println(OUTdetection);
  if(peopleVal < 0)
  {
    peopleVal = 0; 
  }
   lcd.setCursor(7,1);
  lcd.print(peopleVal);
  Serial.println("human : ");
  Serial.println(peopleVal);
  //delay(1000);
   }
  }
