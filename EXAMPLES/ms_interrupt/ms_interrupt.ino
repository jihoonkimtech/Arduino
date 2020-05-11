#include <avr/io.h>
#include <avr/interrupt.h>

volatile int stack = 0;
volatile bool isOn = false;

void setup() {
  TCCR0A = 0; //TCCR0A initialize
  TCCR0B = 0; //TCCR0B initialize
  TCNT0 = 0;  //TCNT0 initialize
  OCR0A= 155; //Period: 10ms , Frequency: 100Hz
  TCCR0A |= (1<<WGM01);
  TCCR0B |= (1<<CS02) | (1<<CS00);
  TIMSK0 |= (1<<OCIE0A);
  sei();

  DDRD = B00001100; 

  Serial.begin(9600);
}

ISR(TIMER0_COMPA_vect)
{
  if(++stack == 100){
    isOn = !isOn;
    stack = 0;
  }
}

void loop() {
  Serial.println(isOn);
  if(isOn){
    PORTD = 0b00001100;
  } else {
    PORTD = 0b00000000;
  }
      
}
