bool gameStarted = false;
int gameMode = 0;
String gameModes[2] = {
  "Domination",
  "Search & Destroy"
};
bool buttonsAttached = false;

void setupMenu() {
  if (!buttonsAttached) {
    blackBtn.attachClick(startGame);
    greenBtn.attachClick(changeGameMode);
    buttonsAttached = true;
  }
  if (gameStarted) {
    startGame();
  } else {
    mainMenu();
  }
}

void mainMenu() {
  writeLcd("Select game mode:", "> " + gameModes[gameMode]);
  delay(100);
}

void startGame() {
  gameStarted = true;
  if (gameMode == 0) {
    setupDomination();
  }
  if (gameMode == 1) {
    setupSed();
  }
}

void changeGameMode() {
  if (gameMode == 1) {
    gameMode = 0;
  } else {
    gameMode++;
  }
}
