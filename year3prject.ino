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
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
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
void temp() {
  int val = d.read11(2); //output pin ti D2
  int t = d.temperature;
  int h = d.humidity;
  //text1(t, h);
  people(t,h);
  r = 0;
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

void start() {

  lcd.setCursor(5, 0);
  lcd.print("Hello,");
  lcd.setCursor(4, 1);
  lcd.print("Everyone");
  delay(1000);
  resets();
  lcd.setCursor(0, 0);
  lcd.print("Scaning Sensors");
  for (int i = 0; i < 3; i++) {
    lcd.setCursor(i, 1);
    lcd.print("-");
    delay(150);
  }
  for (int i = 3; i < 7; i++) {
    lcd.setCursor(i, 1);
    lcd.print("-");
    delay(100);
  }
  for (int i = 1; i < 7; i++) {
    lcd.setCursor(7, 1);
    lcd.print("-");
    delay(200);
    lcd.setCursor(7, 1);
    lcd.print(" ");
    delay(200);
  }
  lcd.setCursor(7, 1);
  lcd.print("-");
  delay(200);
  for (int i = 8; i < 16; i++) {
    lcd.setCursor(i, 1);
    lcd.print("-");
    delay(50);
  }

  delay(500);
  resets();
  lcd.setCursor(0, 0);
  lcd.print("Project is ready");
  delay(500);
  lcd.setCursor(4, 1);
  lcd.print("Starting");
  delay(1000);
  resets();
  sets();
  delay(190);
  resets();
  delay(100);
  sets();
  delay(190);

}

void resets() {
  for (int i = 0; i < 16; i++) {
    lcd.setCursor(i, 0);
    lcd.print(" ");
  }
  for (int i = 0; i < 16; i++) {
    lcd.setCursor(i, 1);
    lcd.print(" ");
  }
}
void sets() {
  for (int i = 0; i < 16; i++) {
    lcd.setCursor(i, 0);
    lcd.print("8");
  }
  for (int i = 0; i < 16; i++) {
    lcd.setCursor(i, 1);
    lcd.print("8");
  }
}
