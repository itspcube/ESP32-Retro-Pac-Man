#ifndef MAZE_LIST_H
#define MAZE_LIST_H

#include "config.h"

/*
 * ╔══════════════════════════════════════════════════╗
 * ║              MAZE CATALOG                        ║
 * ╠══════════════════════════════════════════════════╣
 * ║  Add your own mazes below!                       ║
 * ║                                                  ║
 * ║  Rules:                                          ║
 * ║   - Each maze must be 16 chars wide, 8 rows tall ║
 * ║   - '#' = wall,  '.' = dot,  ' ' = empty path   ║
 * ║   - Surround the maze with '#' borders           ║
 * ║   - Keep (1,1) open for Pac-Man spawn            ║
 * ║   - Keep (14,6) open for Ghost spawn             ║
 * ║                                                  ║
 * ║  To add a maze:                                  ║
 * ║   1. Add a name to MAZE_NAMES                    ║
 * ║   2. Add the maze grid to MAZE_LIST              ║
 * ║   MAZE_COUNT updates automatically.              ║
 * ╚══════════════════════════════════════════════════╝
 */

// ─── Maze names (shown in selection menu) ───
static const char* const MAZE_NAMES[] = {
  "Classic",
  "Arena",
  "Corridors",
  "Zigzag",
  "Chambers"

  // Add your maze name here!
};

// ─── Maze layouts ───
static const char MAZE_LIST[][MAP_H][MAP_W + 1] = {

  // ── Maze 1: Classic ──
  {
    "################",
    "#......##......#",
    "#.##.#....#.##.#",
    "#....#.##.#....#",
    "#.##........##.#",
    "#....##..##....#",
    "#.##........##.#",
    "################"
  },

  // ── Maze 2: Arena ──
  {
    "################",
    "#..............#",
    "#.##........##.#",
    "#.....####.....#",
    "#.....####.....#",
    "#.##........##.#",
    "#..............#",
    "################"
  },

  // ── Maze 3: Corridors ──
  {
    "################",
    "#.....#..#.....#",
    "#.###......###.#",
    "#.....#..#.....#",
    "#..#........#..#",
    "#.....####.....#",
    "#..#........#..#",
    "################"
  },

  // ── Maze 4: Zigzag ──
  {
    "################",
    "#..........#...#",
    "#.####..#..#.#.#",
    "#......##......#",
    "#.##..........##",
    "#....#..##.#...#",
    "#.#..#.........#",
    "################"
  },

  // ── Maze 5: Chambers ──
  {
    "################",
    "#..#......#....#",
    "#..#.####.#..#.#",
    "#..........#...#",
    "#.#..........#.#",
    "#.#.####.##..#.#",
    "#...#........#.#",
    "################"
  }

  // ── Add your maze here! ──
  // 1. Add the name to MAZE_NAMES above
  // 2. Add the grid here (don't forget the comma after the previous })
};

// Auto-count — no need to update manually
#define MAZE_COUNT (sizeof(MAZE_LIST) / sizeof(MAZE_LIST[0]))

#endif // MAZE_LIST_H
