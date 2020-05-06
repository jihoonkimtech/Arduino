#include <SoftwareSerial.h>
#include <DFMiniMp3.h>

const byte interruptPin = 2;
volatile byte state = LOW;

class Mp3Notify
{
public:
  static void OnError(uint16_t errorCode)
  {
    // see DfMp3_Error for code meaning
    Serial.println();
    Serial.print("Com Error ");
    Serial.println(errorCode);
  }

  static void OnPlayFinished(uint16_t globalTrack)
  {
    Serial.println();
    Serial.print("Play finished for #");
    Serial.println(globalTrack);   
  }

  static void OnCardOnline(uint16_t code)
  {
    Serial.println();
    Serial.print("Card online ");
    Serial.println(code);     
  }

  static void OnUsbOnline(uint16_t code)
  {
    Serial.println();
    Serial.print("USB Disk online ");
    Serial.println(code);     
  }

  static void OnCardInserted(uint16_t code)
  {
    Serial.println();
    Serial.print("Card inserted ");
    Serial.println(code); 
  }

  static void OnUsbInserted(uint16_t code)
  {
    Serial.println();
    Serial.print("USB Disk inserted ");
    Serial.println(code); 
  }

  static void OnCardRemoved(uint16_t code)
  {
    Serial.println();
    Serial.print("Card removed ");
    Serial.println(code);  
  }

  static void OnUsbRemoved(uint16_t code)
  {
    Serial.println();
    Serial.print("USB Disk removed ");
    Serial.println(code);  
  }
};

SoftwareSerial secondarySerial(10, 11);
DFMiniMp3<SoftwareSerial, Mp3Notify> mp3(secondarySerial);

int red = 8, grn = 9, buz = 14;
void setup(){
    pinMode(red,OUTPUT);
    pinMode(grn, OUTPUT);
    mp3.begin();
    mp3.setVolume(24);

    pinMode(interruptPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(interruptPin), app, CHANGE);
    
}
void loop(){
    digitalWrite(grn, 0);
    digitalWrite(red, 1);
    if(state == 1){
      mp3.playMp3FolderTrack(1);
      delay(4000);

      mp3.playMp3FolderTrack(3);
      delay(4000);
      delay(2000);
      state = !state;
    }
    else{
      delay(10000);
    }

    
    digitalWrite(red, 0);
    digitalWrite(grn, 1);
    if(state == 1){
      mp3.playMp3FolderTrack(2);
      delay(4000);
      mp3.playMp3FolderTrack(3);
      delay(4000);
      for(int i = 0; i < 5; i++){
        digitalWrite(grn, 1);
        tone(buz,500,500);delay(200);noTone(buz);delay(100);
        tone(buz,500,500);delay(200);noTone(buz);
        //beep-beep
        digitalWrite(grn, 0);
        delay(500);
      }
      state = !state;
    }
    else{
        delay(8000);
        for(int i = 0; i < 5; i++){
          digitalWrite(grn, 1);
          delay(500);
        //beep-beep
          digitalWrite(grn, 0);
          delay(500);
      }
    }
}

void app() {
  state = 1;
}
