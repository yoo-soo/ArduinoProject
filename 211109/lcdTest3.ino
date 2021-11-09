#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  
  long duration = pulseIn(3, HIGH);
  if(duration == 0){
    return;
  }
  long distance = duration / 58.2;
  int light = analogRead(A0);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Distace : ");
  lcd.print(distance);
  delay(100);
 }
