#include <LiquidCrystal_I2C.h>

const int col = 16;
const int row = 2;
LiquidCrystal_I2C lcd(0x27, col, row);

int position = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  lcd.clear();
  lcd.setCursor(position, 0);
  lcd.print("Wahyudin");
  lcd.setCursor(position, 1);
  lcd.print("Youtube");
  position += 1;

  if(position < 0 || position >= col) {
    position = 0;
  }
  delay(500);

}
