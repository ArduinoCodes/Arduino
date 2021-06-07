#include <Wire.h>
#include <dht.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int k = 1000;
int n = 0;
dht d;

int HUM = 62;
int TEM = 25;

void setup()
{
  lcd.begin();
  lcd.backlight();
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  start();
  resets();
  temp();
}
int r = 0;
void loop()
{
  r++;
  if (r > 100) {
    temp();
  }
  people();
  delay(10);
}
void light() {


}

void people(int t,int h) {
  if (digitalRead(3) == LOW) {
    n--;
    text2(n);
    delay(k);
  }
  else if (digitalRead(4) == LOW) {
    n++;
    text2(n);
    delay(k);
  }
  else {
    text2(n);
  }
  if (n > 0) {
    digitalWrite(9, LOW);
    lcd.setCursor(11, 1);
    lcd.print("L");
  }
  else {
    digitalWrite(9, HIGH);
    lcd.setCursor(11, 1);
    lcd.print("_");
  }
  text1(t, h,n);
}

void text1( int t, int h,int n) {
  lcd.setCursor(0, 0);
  lcd.print("Tem:");
  lcd.setCursor(4, 0);
  lcd.print(t - 4);
  lcd.setCursor(7, 0);
  lcd.print("|");
  lcd.setCursor(9, 0);
  lcd.print("Hum:");
  lcd.setCursor(13, 0);
  lcd.print(h);
  if ((t > TEM || h > HUM)& n>0) {
    digitalWrite(8, LOW);
    lcd.setCursor(13, 1);
    lcd.print("F");
  }
  else {
    digitalWrite(8, HIGH);
    lcd.setCursor(13, 1);
    lcd.print("_");
  }
}
void text2(int n) {

  lcd.setCursor(0, 1);
  lcd.print("Count :");
  lcd.setCursor(7, 1);
  if (n < 0) {
    n = 0;
  }
  lcd.print(n);

}




