#include "sound.h"

void beep(int freq, int duration) {

  ledcWriteTone(BUZZER_CHANNEL, freq);

  delay(duration);

  ledcWriteTone(BUZZER_CHANNEL, 0);
}

// PACMAN INTRO MUSIC
void playPacmanIntro() {

  int melody[] = {
    988, 988, 988,
    784, 1047,
    988, 784, 1047,
    988
  };

  int duration[] = {
    150, 150, 150,
    100, 300,
    150, 100, 400,
    500
  };

  for (int i = 0; i < 9; i++) {

    ledcWriteTone(BUZZER_CHANNEL, melody[i]);

    delay(duration[i]);

    ledcWriteTone(BUZZER_CHANNEL, 0);

    delay(40);
  }
}
