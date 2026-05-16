#include "ghost.h"
#include "maze.h"
#include "sound.h"
#include "game.h"
#include "pacman.h"

// ─── Ghost state ───
int ghostX = 14;
int ghostY = 6;

void moveGhostRandom() {

  int dx = 0;
  int dy = 0;

  // Chase player most of the time
  if (random(100) < 75) {

    if (abs(pacX - ghostX) > abs(pacY - ghostY)) {

      if (pacX > ghostX)
        dx = 1;
      else if (pacX < ghostX)
        dx = -1;

    } else {

      if (pacY > ghostY)
        dy = 1;
      else if (pacY < ghostY)
        dy = -1;
    }
  }

  // Random movement sometimes
  else {

    int dir = random(4);

    if (dir == 0) dx = 1;
    if (dir == 1) dx = -1;
    if (dir == 2) dy = 1;
    if (dir == 3) dy = -1;
  }

  int nextX = ghostX + dx;
  int nextY = ghostY + dy;

  // Move if not wall
  if (!isWall(nextX, nextY)) {

    ghostX = nextX;
    ghostY = nextY;
  }
}

void drawGhost() {

  int px = ghostX * TILE;
  int py = ghostY * TILE;

  // Head
  display.fillCircle(px + 4, py + 3, 3, SH110X_WHITE);

  // Body
  display.fillRect(px + 1, py + 3, 6, 4, SH110X_WHITE);

  // Bottom wave
  display.drawLine(px + 1, py + 7, px + 2, py + 6, SH110X_WHITE);
  display.drawLine(px + 3, py + 6, px + 4, py + 7, SH110X_WHITE);
  display.drawLine(px + 5, py + 7, px + 6, py + 6, SH110X_WHITE);

  // Eyes
  display.fillRect(px + 2, py + 2, 2, 2, SH110X_BLACK);
  display.fillRect(px + 5, py + 2, 2, 2, SH110X_BLACK);
}

void checkCollision() {

  if (pacX == ghostX && pacY == ghostY) {

    gameOver = true;

    beep(400, 120);

    delay(80);

    beep(250, 180);
  }
}
