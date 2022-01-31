#include <Arduino.h>

void reg_load(int bits[], int len);
void reg_shift(int bit);
void reg_latch();
void reg_high_all();
void reg_low_all();
void clock_interrupt();


int data_bit=18;//место входа битов
int latch_bit=19; //защелка
int clock_bit=5;//добавляет входящий бит
int button1_pin=5; //видимо неправда
int button2_pin=4; //и это тоже
int button3_pin=4; //не понятно какой тут пин
void setup() {
  Serial.begin(9600);
  
  //int out_bit[8]={};//инициализировал нулями

  pinMode(data_bit, OUTPUT);
  pinMode(latch_bit, OUTPUT);
  pinMode(clock_bit, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);

  digitalWrite(data_bit, LOW);
  digitalWrite(latch_bit, LOW);
  digitalWrite(clock_bit, LOW);



  attachInterrupt(4, clock_interrupt, RISING);//не понятно какой пин тут указывать
  // put your setup code here, to run once:
}

void loop() {

  data_bit = digitalRead(button2_pin);
  latch_bit = digitalRead(button3_pin);
  if(latch_bit==1)
  {
    reg_latch();
  }

  
  //digitalWrite(12, HIGH);

  //digitalWrite(14, HIGH);

  // put your main code here, to run repeatedly:
}
void reg_load(int bits[], int len)
{
  for(int i=0; i<len; i++)
  {
    reg_shift(bits[i]);
  }
}

void reg_shift(int bit)
{
  digitalWrite(clock_bit, LOW);
  digitalWrite(data_bit, bit);
  digitalWrite(clock_bit, HIGH);
  digitalWrite(clock_bit, LOW);
}

void reg_latch()
{
  digitalWrite(latch_bit, LOW);
  digitalWrite(latch_bit, HIGH);
  digitalWrite(latch_bit, LOW);
}

void reg_high_all()
{
  int a[8];
  for(int i=0; i<8; i++)
  {
    a[i]=1;
    reg_load(a,8);

  }
}

void reg_low_all()
{
  int a[8];
  for(int i=0; i<8; i++)
  {
    a[i]=0;
    reg_load(a,8);

  }
}

void clock_interrupt()
{
  reg_shift(data_bit);
}

