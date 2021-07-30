#include "ProgressBar.h"
#include "LCD_I2C.h"

ProgressBar::ProgressBar(int width, LCD_I2C *l) {
  LCD_WIDTH = width;
  lcd = l;
}

void ProgressBar::update(unsigned long count, unsigned long totalCount, int lineToPrintOn) {
  double factor = totalCount / 80.0;          
  int percent = (count+1) / factor;
  int number = percent / 5;
  int remainder = percent % 5;
  if (number > 0) {
    for(int j = 0; j < number; j++){
      lcd->setCursor(j, lineToPrintOn);
      lcd->write(5);
    }
  }
  lcd->setCursor(number, lineToPrintOn);
  lcd->write(remainder); 
  if (number < LCD_WIDTH) {
    for(int j = number+1; j <= LCD_WIDTH; j++) {
      lcd->setCursor(j, lineToPrintOn);
      lcd->write(0);
    }
  }  
}