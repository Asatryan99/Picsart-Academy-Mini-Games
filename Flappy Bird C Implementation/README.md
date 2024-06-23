# Flappy Bird C Implementation

This project is a simple command-line version of the popular game "Flappy Bird" implemented in C. The game features a bird that the player controls to navigate through gaps in barriers by pressing the space bar to make the bird "flap" upwards. The game continues until the bird hits a barrier or the ground, at which point the game is over and the score is displayed.

## Features

- Simple, text-based graphical interface
- Real-time interaction with non-blocking input
- Randomly generated barriers
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
gcc -o flappyBird main.c
```

### Running the Program

After compiling, you can run the program using:

```bash
./flappyBird
```

## Gameplay

- Press the space bar to make the bird flap upwards.
- Avoid hitting the barriers or the ground.
- Press `q` to quit the game at any time.
- The score increases as you successfully navigate through the barriers.

## Code Overview

### Main Loop

The main loop initializes the game map, sets up non-blocking input, and starts the game. The bird's position is updated based on user input, and new barriers are generated randomly. The game ends when the bird collides with a barrier or the ground.

### Functions

- `map_print`: Prints the current state of the game map.
- `enable_nonblock_mode`: Configures the terminal to accept non-blocking input.
- `main`: Initializes the game, enters the main loop, and handles user input and game logic.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
