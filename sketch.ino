#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  lcd.begin(20,4);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Waktu Pengerjaan");
  delay(2000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(4,0);
  lcd.print("UTS 2024");
  lcd.setCursor(7, 1);
  lcd.print(millis()/1000);
  delay(2000);
  lcd.clear();
}
