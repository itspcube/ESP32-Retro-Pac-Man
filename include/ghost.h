#ifndef GHOST_H
#define GHOST_H

#include "config.h"

// ─── Ghost state ───
extern int ghostX;
extern int ghostY;

// Move ghost (chase + random)
void moveGhostRandom();

// Draw ghost sprite
void drawGhost();

// Check if ghost caught Pac-Man
void checkCollision();

#endif // GHOST_H
