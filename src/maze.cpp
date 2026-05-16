#include "maze.h"
#include "maze_list.h"
#include "pacman.h"

// ─── Mutable copy used at runtime ───
char maze[MAP_H][MAP_W + 1];

// ─── Selected maze (set from menu, defaults to 0) ───
int selectedMaze = 0;

void loadMaze() {
  // Start from selected maze, cycle through on level-up
  int mazeIndex = (selectedMaze + level - 1) % MAZE_COUNT;
  memcpy(maze, MAZE_LIST[mazeIndex], sizeof(maze));
}

// ─── Mini preview (half scale: 4px per tile = 64x32) ───
void drawMazePreview(int mazeIndex, int offsetX, int offsetY) {

  const int S = 4; // mini tile size

  for (int y = 0; y < MAP_H; y++) {

    for (int x = 0; x < MAP_W; x++) {

      int px = offsetX + x * S;
      int py = offsetY + y * S;
      char cell = MAZE_LIST[mazeIndex][y][x];

      if (cell == '#') {

        // Draw wall edges (same logic as drawMaze, but mini)
        if (y == 0 || MAZE_LIST[mazeIndex][y - 1][x] != '#')
          display.drawLine(px, py, px + S, py, SH110X_WHITE);

        if (y == MAP_H - 1 || MAZE_LIST[mazeIndex][y + 1][x] != '#')
          display.drawLine(px, py + S, px + S, py + S, SH110X_WHITE);

        if (x == 0 || MAZE_LIST[mazeIndex][y][x - 1] != '#')
          display.drawLine(px, py, px, py + S, SH110X_WHITE);

        if (x == MAP_W - 1 || MAZE_LIST[mazeIndex][y][x + 1] != '#')
          display.drawLine(px + S, py, px + S, py + S, SH110X_WHITE);
      }
      else if (cell == '.') {

        display.drawPixel(px + 2, py + 2, SH110X_WHITE);
      }
    }
  }
}

bool isWall(int x, int y) {

  return maze[y][x] == '#';
}

bool levelComplete() {

  for (int y = 0; y < MAP_H; y++) {

    for (int x = 0; x < MAP_W; x++) {

      if (maze[y][x] == '.') {

        return false;
      }
    }
  }

  return true;
}

void drawMaze() {

  for (int y = 0; y < MAP_H; y++) {

    for (int x = 0; x < MAP_W; x++) {

      int px = x * TILE;
      int py = y * TILE;

      // WALLS
      if (maze[y][x] == '#') {

        // Top
        if (y == 0 || maze[y - 1][x] != '#') {

          display.drawLine(
            px,
            py,
            px + TILE,
            py,
            SH110X_WHITE
          );
        }

        // Bottom
        if (y == MAP_H - 1 || maze[y + 1][x] != '#') {

          display.drawLine(
            px,
            py + TILE,
            px + TILE,
            py + TILE,
            SH110X_WHITE
          );
        }

        // Left
        if (x == 0 || maze[y][x - 1] != '#') {

          display.drawLine(
            px,
            py,
            px,
            py + TILE,
            SH110X_WHITE
          );
        }

        // Right
        if (x == MAP_W - 1 || maze[y][x + 1] != '#') {

          display.drawLine(
            px + TILE,
            py,
            px + TILE,
            py + TILE,
            SH110X_WHITE
          );
        }
      }

      // DOTS
      else if (maze[y][x] == '.') {

        display.fillCircle(
          px + 4,
          py + 4,
          1,
          SH110X_WHITE
        );
      }
    }
  }
}
