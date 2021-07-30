#include <Arduino.h>
#include <OneButton.h>
#include <LCD_I2C.h>
#include "pinout.h"
#include "lcdChars.h"

LCD_I2C lcd(0x27);

OneButton blackBtn = OneButton(BLACK_BTN, true, true);
OneButton greenBtn = OneButton(GREEN_BTN, true, true);
OneButton redBtn = OneButton(RED_BTN, true, true);

bool gameStarted = false;

void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.createChar(0, char_zero);
  lcd.createChar(1, char_one);
  lcd.createChar(2, char_two);
  lcd.createChar(3, char_three);
  lcd.createChar(4, char_four);
  lcd.createChar(5, char_five);
}

void loop() {
  setupMenu();
  blackBtn.tick();
  greenBtn.tick();
  redBtn.tick();
}
