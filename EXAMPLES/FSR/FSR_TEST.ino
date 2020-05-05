/*
 * 2020-03-2n
 * FSR SENSER AND LED
 * by. jihoonkimtech (aka hanul)
 */
 
const int FSR_SENSOR = 14; //A0와 같습니다.
const int RED_LED = 11; //A1과 같습니다.

void setup() {
  /*
  analog function 사용시 따로 핀 모드 지정이 필요 없습니다.
  pinMode(FSR_SENSOR, INPUT);
  pinMode(RED_LED, OUTPUT); 
  */
  Serial.begin(9600);
}

void loop() {
  int fsrRead = analogRead(FSR_SENSOR);
  if(fsrRead > 900) fsrRead = 900;
  //Serial.println(fsrRead);
  int ledValue = map(fsrRead, 0, 900, 0, 255);
  Serial.println(ledValue);
  analogWrite(RED_LED, ledValue);
  delay(10);
}
