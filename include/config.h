#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

// ─── Screen ───
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// ─── OLED I2C Pins ───
#define SDA_PIN 21
#define SCL_PIN 22

// ─── Joystick ───
#define JOY_X 34
#define JOY_Y 35

// ─── Button ───
#define BTN1 23

// ─── Buzzer ───
#define BUZZER 27
#define BUZZER_CHANNEL 0
#define BUZZER_RESOLUTION 8

// ─── Grid / Map ───
#define TILE 8
#define MAP_W 16
#define MAP_H 8

// ─── Shared display instance ───
extern Adafruit_SH1106G display;

#endif // CONFIG_H
