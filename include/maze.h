#ifndef MAZE_H
#define MAZE_H

#include "config.h"

// ─── Maze data ───
extern char maze[MAP_H][MAP_W + 1];

// ─── Selected maze index (set from menu) ───
extern int selectedMaze;

// Reload the maze to its original layout
void loadMaze();

// Check if a tile is a wall
bool isWall(int x, int y);

// Check if all dots have been eaten
bool levelComplete();

// Draw the maze walls and dots (full size)
void drawMaze();

// Draw a mini maze preview at the given position (for selection menu)
void drawMazePreview(int mazeIndex, int offsetX, int offsetY);

#endif // MAZE_H
