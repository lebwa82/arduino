#include <Arduino.h>

int input_bit=14;//место входа битов
int latch=12; //защелка
int add_bit=11;//добавляет входящий бит
void setup() {
  Serial.begin(9600);
  
  //int out_bit[8]={};//инициализировал нулями

  pinMode(input_bit, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(add_bit, OUTPUT);

  digitalWrite(input_bit, LOW);
  digitalWrite(latch, LOW);
  digitalWrite(add_bit, LOW);





  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}

void shift(int *bits, int len)
{
  int i;
  for(i-0; i<len; i++)
  {
    digitalWrite(add_bit, LOW);
    digitalWrite(input_bit, bits[i]);
    digitalWrite(add_bit, HIGH);
  }
  digitalWrite(latch, HIGH);

  digitalWrite(input_bit, LOW);
  digitalWrite(latch, LOW);
  digitalWrite(add_bit, LOW);
  
}