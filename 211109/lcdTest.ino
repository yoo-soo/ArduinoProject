#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello World");
  lcd.setCursor(0, 1);
  lcd.print("Hallym software");
  delay(1000);

  lcd.init();
  lcd.setCursor(1, 0);
  lcd.print("1");
  lcd.setCursor(3, 1);
  lcd.print("2");
  delay(1000);
}
