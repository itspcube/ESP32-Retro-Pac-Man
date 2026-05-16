#ifndef GAME_H
#define GAME_H

#include "config.h"

// ─── Game state ───
extern bool gameStarted;
extern bool gameOver;

// ─── Score & Level ───
extern int score;
extern int level;

// ─── Ghost speed ───
extern int ghostDelay;

// Reset all game state for a fresh start
void resetGame();

// Advance to the next level
void nextLevel();

// Draw score and level HUD
void drawHUD();

// Show the start menu screen
void showStartMenu();

// Show the game-over screen
void showGameOver();

#endif // GAME_H
