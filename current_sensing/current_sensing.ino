#define R1 30000.0
#define R2 7500.0
#define ANALOG_MAX 1024.0
#define MUITPLE 5.0
#define SENSORPIN A1
#define SENSORPINVOLT A0 //voltageSensor

float voltageRead(int pin);
float currentRead(int pin);

void setup() {
  pinMode(SENSORPIN, INPUT);
  pinMode(SENSORPINVOLT, INPUT);
  Serial.begin(9600);
  Serial.println("CURRENT DETECTOR");
  Serial.println("");
}

void loop() {
  Serial.print("read current value : ");
  Serial.print(currentRead(SENSORPIN, SENSORPINVOLT));
  Serial.println(" mA");
  Serial.println("");
  delay(500);
}

float currentRead(int cur_sen_pin, int volt_sen_pin){
  int analogInCur = analogRead(cur_sen_pin);
  int analogInVolt = analogRead(volt_sen_pin);

  float volt1 = (analogInVolt * MUITPLE) / ANALOG_MAX;
  float volt2 = volt1 / (R2/(R1+R2));
  int volt3 = volt2*100;
  
  float amp = (((analogInCur-511)*5/0.185)/1024)*1000;
  Serial.print("(V : ");
  Serial.print(volt2);
  Serial.print(") ");
  
  return amp;
}
