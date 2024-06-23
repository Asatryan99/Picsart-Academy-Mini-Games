# Falling Blocks Game

This project is a simple command-line game where the player controls a falling object, trying to avoid collisions and clear rows to gain points. The game is implemented in C and demonstrates concepts such as real-time user input handling, terminal control, and basic game mechanics.

## Features

- Real-time interaction with non-blocking input
- Simple, text-based graphical interface
- Row-clearing mechanics similar to Tetris
- Score tracking

## Getting Started

### Prerequisites

- C compiler (e.g., `gcc`)
- Unix-like operating system (Linux, macOS)

### Files

- `main.c`: Contains the main function and game logic.

### Compiling the Program

To compile the program, use the following command:

```bash
gcc -o fallingBlocks main.c
```

### Running the Program

After compiling, you can run the program using:

```bash
./fallingBlocks
```

## Gameplay

- Use the `a` key to move the falling object left.
- Use the `d` key to move the falling object right.
- Press `q` to quit the game at any time.
- Clear rows by filling them with the object to increase your score.
- The game ends if the falling object collides with another object below it.

## Code Overview

### Main Loop

The main loop initializes the game map, sets up non-blocking input, and starts the game. The object's position is updated based on user input, and rows are checked for completion. The game ends when the object collides with another object.

### Functions

- `map_print`: Prints the current state of the game map.
- `map_body_dump`: Shifts the map down when a row is cleared.
- `enable_nonblock_mode`: Configures the terminal to accept non-blocking input.
- `main`: Initializes the game, enters the main loop, and handles user input and game logic.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
