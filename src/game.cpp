#include "game.h"
#include "ghost.h"
#include "maze.h"
#include "maze_list.h"
#include "pacman.h"
#include "sound.h"

// ─── Game state ───
bool gameStarted = false;
bool gameOver = false;

// ─── Ghost speed ───
int ghostDelay = 180;

void resetGame() {

  pacX = 1;
  pacY = 1;

  ghostX = 14;
  ghostY = 6;

  score = 0;
  level = 1;

  ghostDelay = 180;

  gameOver = false;

  loadMaze();
}

void nextLevel() {

  display.clearDisplay();

  display.setTextSize(2);

  display.setCursor(10, 10);
  display.println("YOU");

  display.setCursor(10, 30);
  display.println("WON");

  display.setTextSize(1);

  display.setCursor(10, 55);
  display.println("PRESS BTN1");

  display.display();

  beep(1200, 80);

  delay(50);

  beep(1600, 120);

  // Wait for button
  while (digitalRead(BTN1) == HIGH) {

    delay(10);
  }

  delay(300);

  level++;

  pacX = 1;
  pacY = 1;

  ghostX = 14;
  ghostY = 6;

  // Faster ghost every level
  if (ghostDelay > 70) {

    ghostDelay -= 15;
  }

  loadMaze();
}

void drawHUD() {

  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);

  display.setCursor(82, 0);
  display.print("S:");
  display.print(score);

  display.setCursor(82, 10);
}

void showStartMenu() {

  static bool selectingMaze = false;
  static int browseIndex = 0;
  static unsigned long lastJoyMove = 0;

  // ── Phase 1: Title screen ──
  if (!selectingMaze) {

    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SH110X_WHITE);

    display.setCursor(16, 8);
    display.println("PACMAN");

    display.setTextSize(1);

    display.setCursor(16, 40);
    display.println("PRESS BTN1");

    display.display();

    if (digitalRead(BTN1) == LOW) {

      delay(250);

      selectingMaze = true;
      browseIndex = 0; // start on the first maze
    }

    return;
  }

  // ── Phase 2: Maze selection ──
  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);

  if (browseIndex == MAZE_COUNT) {

    // ── Tip slide ──
    display.setTextSize(1);
    display.setCursor(16, 5);
    display.print("MAZE SELECT");

    display.setCursor(10, 22);
    display.print("Add your custom");
    display.setCursor(10, 32);
    display.print("maze using the");
    display.setCursor(10, 42);
    display.print("code!");

    display.setCursor(60, 55);
    display.print("< JOY");

    display.display();

  } else {

    // ── Maze preview slide ──
    // Title
    display.setTextSize(1);
    display.setCursor(20, 0);
    display.print("SELECT MAZE");

    // Maze name (centered)
    const char *name = MAZE_NAMES[browseIndex];
    int nameLen = strlen(name);
    int nameX = (128 - nameLen * 6) / 2;
    display.setCursor(nameX, 10);
    display.print(name);

    // Mini maze preview (64x32, centered horizontally)
    drawMazePreview(browseIndex, 32, 20);

    // Navigation arrows
    display.setTextSize(1);
    display.setCursor(18, 34);
    display.print("<");
    display.setCursor(104, 34);
    display.print(">");

    // Maze counter (e.g. "2/5")
    display.setCursor(50, 55);
    display.print(browseIndex + 1);
    display.print("/");
    display.print((int)MAZE_COUNT);

    // "GO" hint
    display.setCursor(80, 55);
    display.print("BTN1:GO");

    display.display();
  }

  // ── Joystick: browse left/right ──
  if (millis() - lastJoyMove > 200) {

    int xVal = analogRead(JOY_Y);

    // LEFT
    if (xVal > 3000) {

      browseIndex--;

      if (browseIndex < 0)
        browseIndex = MAZE_COUNT;

      beep(800, 20);
      lastJoyMove = millis();
    }

    // RIGHT
    else if (xVal < 1000) {

      browseIndex++;

      if (browseIndex > MAZE_COUNT)
        browseIndex = 0;

      beep(800, 20);
      lastJoyMove = millis();
    }
  }

  // ── BTN1: confirm selection (only on maze slides) ──
  if (browseIndex < MAZE_COUNT && digitalRead(BTN1) == LOW) {

    selectedMaze = browseIndex;

    playPacmanIntro();

    delay(200);

    selectingMaze = false;
    gameStarted = true;

    resetGame();
  }
}

void showGameOver() {

  display.clearDisplay();

  display.setTextSize(2);

  display.setCursor(10, 10);
  display.println("GAME");

  display.setCursor(10, 30);
  display.println("OVER");

  display.setTextSize(1);

  display.setCursor(5, 55);
  display.println("BTN1 RESTART");

  display.display();

  // Restart
  if (digitalRead(BTN1) == LOW) {

    delay(300);

    resetGame();
  }
}
