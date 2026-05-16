#include "pacman.h"
#include "maze.h"
#include "sound.h"

// ─── Pac-Man state ───
int pacX = 1;
int pacY = 1;

int dirX = 1;
int dirY = 0;

bool mouthOpen = true;

// ─── Score & Level (defined here, used globally) ───
int score = 0;
int level = 1;

void movePacman() {

  // Axes swapped
  int yVal = analogRead(JOY_X);
  int xVal = analogRead(JOY_Y);

  int nextX = pacX;
  int nextY = pacY;

  // LEFT
  if (xVal > 3000) {

    nextX--;
    dirX = -1;
    dirY = 0;
  }

  // RIGHT
  else if (xVal < 1000) {

    nextX++;
    dirX = 1;
    dirY = 0;
  }

  // UP
  else if (yVal < 1000) {

    nextY--;
    dirX = 0;
    dirY = -1;
  }

  // DOWN
  else if (yVal > 3000) {

    nextY++;
    dirX = 0;
    dirY = 1;
  }

  // MOVE
  if (!isWall(nextX, nextY)) {

    pacX = nextX;
    pacY = nextY;

    // Eat dot
    if (maze[pacY][pacX] == '.') {

      maze[pacY][pacX] = ' ';
      score++;

      beep(1400, 15);
    }
  }

  // Mouth animation
  mouthOpen = !mouthOpen;
}

void drawPacman() {

  int px = pacX * TILE + 4;
  int py = pacY * TILE + 4;

  // BODY
  display.fillCircle(px, py, 3, SH110X_WHITE);

  // MOUTH
  if (mouthOpen) {

    // RIGHT
    if (dirX == 1) {

      display.fillTriangle(
        px,
        py,
        px + 4,
        py - 2,
        px + 4,
        py + 2,
        SH110X_BLACK
      );
    }

    // LEFT
    if (dirX == -1) {

      display.fillTriangle(
        px,
        py,
        px - 4,
        py - 2,
        px - 4,
        py + 2,
        SH110X_BLACK
      );
    }

    // UP
    if (dirY == -1) {

      display.fillTriangle(
        px,
        py,
        px - 2,
        py - 4,
        px + 2,
        py - 4,
        SH110X_BLACK
      );
    }

    // DOWN
    if (dirY == 1) {

      display.fillTriangle(
        px,
        py,
        px - 2,
        py + 4,
        px + 2,
        py + 4,
        SH110X_BLACK
      );
    }
  }
}
