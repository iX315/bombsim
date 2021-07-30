#include "Domination.h"
#include "OneButton.h"

Domination::Domination(OneButton *b, OneButton *g, OneButton *r) {
  b = blackBtn;
  g = greenBtn;
  r = redBtn;
}

void Domination::init() {
  if (!buttonsAttached) {
    greenBtn->setPressTicks(300);
    redBtn->setPressTicks(300);
    blackBtn->attachClick(config);
    greenBtn->attachDuringLongPress(greenTimer);
    redBtn->attachDuringLongPress(redTimer);
    timerRed = setupTime;
    timerBlue = setupTime;
    buttonsAttached = true;
  }
  if (showConfig) {
    config();
  } else if (gameStarted) {
    mainLoop();
  } else {
    // main screen
    writeLcd("(G)(R) start", "(B) config");
    delay(100);
  }
}

void Domination::config() {
  showConfig = true;
  if (!buttonsAttachedConfig) {
    blackBtn->attachClick(exitConfig);
    greenBtn->attachDuringLongPress(theVoid);
    redBtn->attachDuringLongPress(theVoid);
    greenBtn->attachClick(decreaseSeconds);
    redBtn->attachClick(increaseSeconds);
    buttonsAttachedConfig = true;
  }
  writeLcd(" -(G) [" + String(round(setupTime)) + "s] (R)+", "(B) back");
  delay(100);
}

void Domination::exitConfig() {
  showConfig = false;
  buttonsAttached = false;
  blackBtn->attachClick(theVoid);
  greenBtn->attachClick(theVoid);
  redBtn->attachClick(theVoid);
}

void Domination::decreaseSeconds() {
  if (setupTime > 1) {
    setupTime = setupTime - 1;
  }
}

void Domination::increaseSeconds() {
  setupTime = setupTime + 1;
}

void Domination::mainLoop() {
  if (timerRed > timerBlue) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }
  if (timerRed < timerBlue) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  }
  if (timerRed <= 0) {
    // red wins
    gameOver("RED");
  }
  if (timerBlue <= 0) {
    // green wins
    gameOver("GREEN");
  }
}

void Domination::greenTimer() {
  gameStarted = true;
  timerBlue = timerBlue - 0.1;
  writeLcd("   ** GREEN **");
  updateProgressBar(round(timerBlue * 10), round(setupTime * 10), 1);
}

void Domination::redTimer() {
  gameStarted = true;
  timerRed = timerRed - 0.1;
  writeLcd("    ** RED **");
  updateProgressBar(round(timerRed * 10), round(setupTime * 10), 1);
}