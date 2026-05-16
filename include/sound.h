#ifndef SOUND_H
#define SOUND_H

#include "config.h"

// Play a single tone for the given duration (ms)
void beep(int freq, int duration);

// Play the classic Pac-Man intro jingle
void playPacmanIntro();

#endif // SOUND_H
