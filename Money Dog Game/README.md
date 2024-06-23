# Money Dog Game

This project is a simple command-line game called "Money Dog," where the player controls a character to collect money represented by `$` on a grid while avoiding walls. The game is implemented in C and demonstrates concepts such as real-time user input handling, terminal control, and basic game mechanics.

## Features

- Simple, text-based graphical interface
- Real-time interaction with non-blocking input
- Score tracking based on collected money
- Random placement of money on the grid

## Getting Started

### Prerequisites

- C compiler (e.g., `gcc`)
- Unix-like operating system (Linux, macOS)

### Files

- `main.c`: Contains the main function and game logic.

### Compiling the Program

To compile the program, use the following command:

```bash
gcc -o moneyDog main.c
```

### Running the Program

After compiling, you can run the program using:

```bash
./moneyDog
```

## Gameplay

- Use `w` to move up.
- Use `s` to move down.
- Use `a` to move left.
- Use `d` to move right.
- Press `q` to quit the game at any time.
- Collect money represented by `$` to increase your score.
- Avoid hitting the walls represented by `#`.

## Code Overview

### Main Loop

The main loop initializes the game map, sets up non-blocking input, and starts the game. The player's position is updated based on user input, and the game map is printed after each move. The game continues until the player presses `q`.

### Functions

- `setEchoMode`: Configures the terminal to accept non-blocking input and optionally enable echo.
- `getch`: Gets a single character input without echoing it to the terminal.
- `print_matrix`: Prints the current state of the game map with color-coded elements.
- `main`: Initializes the game, enters the main loop, and handles user input and game logic.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
