#include <OneButton.h>
#include <LCD_I2C.h>

// lcd size
const int LCD_WIDTH = 16;
const int LCD_HEIGHT = 2;

// led pins
const int RED_LED = 5;
const int GREEN_LED = 6;

// button pins
const int BLACK_BTN = 4;
const int RED_BTN = 7;
const int GREEN_BTN = 8;

// buzzer pin for tones
const int BUZZER = 12;

LCD_I2C lcd(0x27);

OneButton blackBtn = OneButton(BLACK_BTN, true, true);
OneButton greenBtn = OneButton(RED_BTN, true, true);
OneButton redBtn = OneButton(GREEN_BTN, true, true);

byte zero[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte one[] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
};
byte two[] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000
};
byte three[] = {
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100
};
byte four[] = {
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110
};
byte five[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

bool gameStarted = false;

void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.createChar(0, zero);
  lcd.createChar(1, one);
  lcd.createChar(2, two);
  lcd.createChar(3, three);
  lcd.createChar(4, four);
  lcd.createChar(5, five);
}

void loop() {
  setupMenu();
  blackBtn.tick();
  greenBtn.tick();
  redBtn.tick();
}
