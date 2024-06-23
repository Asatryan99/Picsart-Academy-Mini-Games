# Hangman Game

This project is a simple command-line implementation of the classic game "Hangman." The player needs to guess the hidden word by suggesting letters within a certain number of tries. The game provides clues for each word to help the player.

## Features

- Simple, text-based graphical interface
- Word list with corresponding clues
- Score tracking based on remaining tries (hearts)
- Option to play again or quit after each round

## Getting Started

### Prerequisites

- C compiler (e.g., `gcc`)
- Unix-like operating system (Linux, macOS)

### Files

- `main.c`: Contains the main function and game logic.

### Compiling the Program

To compile the program, use the following command:

```bash
gcc -o hangman main.c
```

### Running the Program

After compiling, you can run the program using:

```bash
./hangman
```

## Gameplay

1. The game starts with a welcome message and waits for the player to press ENTER to continue.
2. A random word is chosen from the word list, and a clue is displayed to help the player.
3. The player guesses letters one by one to reveal the hidden word.
4. The player has three tries (hearts). If the player guesses a letter incorrectly, a heart is lost.
5. If the player guesses the word correctly, a congratulatory message is displayed, and the player is given the option to play again or quit.
6. If the player runs out of hearts, a game over message is displayed.

## Code Overview

### Main Loop

The main loop initializes the game, selects a random word, and starts the guessing process. The player's input is processed, and the hidden word is updated accordingly. The game continues until the player either guesses the word correctly or runs out of hearts.

### Functions

- `word_checker`: Checks if the entire word has been guessed.
- `main`: Initializes the game, enters the main loop, handles user input and game logic, and displays appropriate messages based on the game state.

### Word List and Clues

The game includes a predefined list of words and corresponding clues:

- `"apple"` - "This is a fruit, and this is also a logo"
- `"bitcoin"` - "This is related to cryptocurrency"
- `"piano"` - "Musical instrument"
- `"burger"` - "Unhealthy but tasty food"
- `"picsart"` - "Best Academy"
- `"interstellar"` - "Best Chris Nolan movie"

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
