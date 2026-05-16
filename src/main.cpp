#include "config.h"
#include "sound.h"
#include "maze.h"
#include "pacman.h"
#include "ghost.h"
#include "game.h"

// ─── Shared display instance ───
Adafruit_SH1106G display(128, 64, &Wire, -1);

void setup() {

  Serial.begin(115200);

  pinMode(BTN1, INPUT_PULLUP);

  Wire.begin(SDA_PIN, SCL_PIN);

  display.begin(0x3C, true);

  // Buzzer setup
  ledcSetup(
    BUZZER_CHANNEL,
    2000,
    BUZZER_RESOLUTION
  );

  ledcAttachPin(
    BUZZER,
    BUZZER_CHANNEL
  );

  randomSeed(analogRead(33));

  loadMaze();
}

void loop() {

  // START MENU
  if (!gameStarted) {

    showStartMenu();
    return;
  }

  // GAME OVER
  if (gameOver) {

    showGameOver();
    return;
  }

  // ── BTN1: back to menu ──
  if (digitalRead(BTN1) == LOW) {

    delay(300);

    gameStarted = false;
    return;
  }

  static unsigned long lastPacMove = 0;
  static unsigned long lastGhostMove = 0;

  // Pacman speed
  if (millis() - lastPacMove > 120) {

    movePacman();

    lastPacMove = millis();
  }

  // Ghost speed
  if (millis() - lastGhostMove > ghostDelay) {

    moveGhostRandom();

    lastGhostMove = millis();
  }

  checkCollision();

  // NEXT LEVEL
  if (levelComplete()) {

    nextLevel();
  }

  // DRAW
  display.clearDisplay();

  drawMaze();

  drawPacman();

  drawGhost();

  drawHUD();

  display.display();
}