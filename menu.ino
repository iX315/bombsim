bool showMainMenu = true;
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
  if (showMainMenu) {
    mainMenu();
  } else {
    startGame();
  }
}

void mainMenu() {
  writeLcd("Select game mode:", "> " + gameModes[gameMode]);
  delay(100);
}

void startGame() {
  // hack - call this 1 time
  if (showMainMenu) {
    blackBtn.attachClick(theVoid);
    greenBtn.attachClick(theVoid);
  }
  showMainMenu = false;
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
