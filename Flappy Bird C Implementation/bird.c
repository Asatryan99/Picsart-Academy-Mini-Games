#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termio.h>
#include <fcntl.h>
#include <string.h>

#define HEIGHT 16
#define LENGTH 20

int score = -1;
void map_print(char map[HEIGHT][LENGTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < LENGTH; j++) {
            if (map[i][j] == 'B') {
                printf("\033[1;33m");
            }
            if (map[i][j] == 'H') {
                printf("\033[1;32m");
            }
            printf("%c ", map[i][j]);
            printf("\033[0m");
        }
        printf("\n");
    }
    printf("\n\t\t\033[1;34mSCORE: %d\n\033[0m", score * 10);
}

void enable_nonblock_mode() {
    struct termios ttystate;
    // Get the terminal state
    tcgetattr(STDIN_FILENO, &ttystate);
    // Turn off canonical mode
    ttystate.c_lflag &= ~ICANON;
    // Minimum number of characters for noncanonical read
    ttystate.c_cc[VMIN] = 1;
    // Set the terminal attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
    // Set non-blocking mode
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

int main ()
{
    char map[HEIGHT][LENGTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < LENGTH; j++) {
            if (i == 0 || j == 0 || i == HEIGHT - 1 || j == LENGTH - 1) {
                map[i][j] = '#';
            } else {
                map[i][j] = ' ';
            }
        }
    }
    system("clear");
    map_print(map);
    srand(time(NULL));
    enable_nonblock_mode();
    
    char bird = 'B';
    int cordX = HEIGHT / 2;
    int cordY = 3;


    while (1) {
        map[cordX][cordY] = bird;

        int randomSIZE = 3 + rand() % 6;
        system("clear");
        for (int i = 1; i < randomSIZE; i++) {
            map[i][LENGTH - 2] = 'H';
        }
        for (int i = HEIGHT - 2; i > randomSIZE + 2; i--) {
            map[i][LENGTH - 2] = 'H';
        }
        map_print(map);
        usleep(110000);
        score++;

        for (int col = LENGTH - 2; col > 0 ; col--) {
            for (int row = 1; row < HEIGHT - 1; row++) {
                if (map[row][col] != bird)
                map[row][col - 1] = map[row][col];
                map[row][col] = ' ';
            }
            for (int i = 0; i < HEIGHT; i++) {
                map[i][0] = '#';
            }
            map[cordX][cordY] = ' ';
            cordX++;
            map[cordX][cordY] = bird;

            char ch;
            read(STDIN_FILENO, &ch, 1);
            if (ch == 'q') {
                return 0; 
            }
            if (ch == ' ' && cordX - 1 != 0) {
                map[cordX][cordY] = ' ';
                cordX -= 3;
                ch = 0;
                map[cordX][cordY] = bird;
            }
            if (cordX == HEIGHT - 1 || (map[cordX][cordY + 1]) == 'H') {
                system("clear");
                map_print(map);
                printf("\n\t\t\033[1;31mGAME OVER\n\033[0m\n");
                return 0;
            }
            system("clear");
            map_print(map);
            usleep(110000);
        }
    }
}