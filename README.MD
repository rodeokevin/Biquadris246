# Biquadris

## Overview

Biquadris is a two-player turn-based Tetris-like game designed as a project for CS246 Fall 2024. Unlike the classic Tetris, Biquadris allows players to take turns strategically placing blocks rather than playing in real-time. The goal is to clear rows by placing tetrominoes efficiently on the board while using special actions to hinder the opponent.

## Features

- **Two-player competitive gameplay**
- **Turn-based mechanics** (players take turns to drop blocks)
- **Text-based and graphical display modes**
- **Multiple difficulty levels**
- **Special actions** (e.g., blinding the opponent’s board, forcing a block change, applying heavy gravity)
- **Command-based input system**
- **Customizable starting configurations via command-line options**

## Game Rules

- Each player has an 11x15 board (with 3 extra rows for rotation buffer).
- Players take turns placing tetrominoes that appear at the top of their board.
- Completed rows disappear, shifting blocks above downward.
- The game ends when a player can no longer place a block.
- Special actions are triggered when a player clears 2+ rows simultaneously.

## Difficulty Levels

1. **Level 0** - Blocks follow a predefined sequence from a file.
2. **Level 1** - Random block selection with increased probability of S/Z blocks.
3. **Level 2** - All blocks appear with equal probability.
4. **Level 3** - Like Level 1, but blocks are "heavy" (they fall after every move/rotation).
5. **Level 4** - Includes "garbage" blocks that drop every 5 moves without clearing a row.

## Special Actions

Triggering two or more row clears in a single move allows players to apply a special effect:

- **Blind** - Covers part of the opponent's board temporarily.
- **Heavy** - Makes opponent’s block fall automatically after horizontal movement.
- **Force** - Changes the opponent’s current block to a specified type.

## Contributors
This project was developed in collaboration with Forrest Chen and Robert Liu.
