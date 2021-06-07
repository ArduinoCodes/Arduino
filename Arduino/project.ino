#include <Wire.h>
#include <dht.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
dht d;

//limitation goes here
int HUM = 62;
int TEM = 25;

void setup(){
lcd.begin();
lcd.backlight();
pinMode(8, OUTPUT);
digitalWrite(8, HIGH);
start();
resets();
}

void loop(){
    temp();
}
void temp() {
  int val = d.read11(2); //output pin ti D2
  int t = d.temperature;
  int h = d.humidity;
  if(t>TEM && h>HUM){
    digitalWrite(8, LOW);
    lcd.setCursor(1, 0);
    lcd.print("AC is ON");
  }
  else{
      digitalWrite(8, HIGH);
      lcd.setCursor(1, 0);
    lcd.print("AC is OFF");
  }
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