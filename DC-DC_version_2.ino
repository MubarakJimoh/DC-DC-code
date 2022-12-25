
#include "LiquidCrystal.h"
#define DCDC 14
#define SSR 15
#define DIGIPOT 17


LiquidCrystal lcd(8,9,4,5,6,7);
int delay_timer = 100;
int x;
int pulse_kount = 0;
int Timelapsed = 0;
bool SSRFLAG = LOW;
int get_pulse();

void setup() {
  pinMode(14,INPUT);
  pinMode(15,OUTPUT);
  pinMode(17,OUTPUT);
}
  int get_pulse()
{
 int pulse_width = 0;
  do
  { delay (delay_timer) ;
  lcd.setCursor(8,1);
  lcd.print(pulse_width++);
  }
  while (digitalRead(14)== LOW);
 
pulse_width=1;
do
{
  pulse_width++;
  delay(delay_timer);
  lcd.setCursor(3, 1);
    lcd.print(pulse_width); 
}
while (digitalRead(14)==HIGH);

return (pulse_width);
}

void loop() {
x = get_pulse(); //* delay_timer;
 if (x!= Timelapsed)
 { lcd.setCursor(3,1);
    lcd.print(x);
    Timelapsed = x;
 }
 lcd.setCursor (8,1);
 lcd.print(++pulse_kount);

 if (pulse_kount==58)
    { pulse_kount = 0;
      SSRFLAG != SSRFLAG;
      digitalWrite (SSR,SSRFLAG);
    }
   // lcd.print(x); 
 //  lcd.setCursor(8, 2); 
   //lcd.print (++pulse_kount);
}

  
