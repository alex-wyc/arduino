#include <LiquidCrystal.h>

LiquidCrystal
lcd(12,11,5,4,3,2);

int h,m,s;
int TIME;

const int hs=8;
const int ms=9;

int button1;
int button2;

void setup() {
//  Serial.begin(9600);
  //Serial.print("HI");
  // put your setup code here, to run once:
  lcd.begin(16,2);
//  Serial.print("DONE");
}

void loop() {
  // put your main code here, to run repeatedly:
    s += 1;
     if (s == 60) {
    s = 0;
    m += 1;
  }

  if (m == 60) {
    m = 0;
    h = (h + 1) % 24;
  }


  lcd.clear();
  lcd.setCursor(0,0);

  lcd.print("TIME: ");
  lcd.print(h);
  lcd.print(":");
  lcd.print(m);
  lcd.print(":");
  lcd.print(s);

//  Serial.print(h);
//  Serial.print(m);
//  Serial.print(s);

 
  lcd.setCursor(0,1);

  if (h < 12) {
    lcd.print("Good Morning!");
  }
  else if (h < 18) {
    lcd.print("Good Afternoon!");
  }
  else if (h < 20) {
    lcd.print("Good Evening!");
  }
  else {
    lcd.print("Good Night!");
  }

  // button controls

  // increment hours
  button1=digitalRead(hs);
  if (button1) {
    h = (h + 1) % 24;
  }

  // increment minutes
  button2 = digitalRead(ms);

  if (button2) {
    s = 0;
    m += 1;

    if (m == 60) {
      m = 0;
      h = (h + 1) % 24;
    }
  }

  delay(1000); // wait till next second
}
