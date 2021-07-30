#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include "LCD_I2C.h"

class ProgressBar {
  public:
    ProgressBar(int width, LCD_I2C *l);
    void update(unsigned long count, unsigned long totalCount, int lineToPrintOn);
  private:
    int LCD_WIDTH;
    LCD_I2C *lcd;
};

#endif