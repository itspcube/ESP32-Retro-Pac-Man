#ifndef PACMAN_H
#define PACMAN_H

#include "config.h"

// ─── Pac-Man state ───
extern int pacX;
extern int pacY;
extern int dirX;
extern int dirY;
extern bool mouthOpen;

// ─── Score & Level (defined in pacman.cpp) ───
extern int score;
extern int level;

// Read joystick and move Pac-Man, eat dots
void movePacman();

// Draw Pac-Man sprite with directional mouth
void drawPacman();

#endif // PACMAN_H
