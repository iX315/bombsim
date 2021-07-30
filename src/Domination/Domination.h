#ifndef DOMINATION_H
#define DOMINATION_H

#include "OneButton.h"

class Domination {
  public:
    Domination(OneButton *b, OneButton *g, OneButton *r);
    void init();
    OneButton *blackBtn;
    OneButton *greenBtn;
    OneButton *redBtn;
    bool gameStarted = false;
    float timerRed;
    float timerBlue;
    float setupTime = 15.0;
    bool buttonsAttached = false;
    bool buttonsAttachedConfig = false;
    bool showConfig = false;
    void decreaseSeconds();
    void increaseSeconds();
    void config();
    void mainLoop();
    void exitConfig();
    void greenTimer();
    void redTimer();
};

#endif