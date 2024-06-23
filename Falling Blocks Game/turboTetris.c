#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define HEIGHT 16
#define LENGTH 11

int score = 0;
void map_print(char map[HEIGHT][LENGTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < LENGTH; j++) {
            if (map[i][j] == 'T') {
                printf("\033[1;31m");
            }
            printf("%c ", map[i][j]);
            printf("\033[0m");
        }
        printf("\n");
    }
    printf("\n      SCORE: %d\n\n", score * 10) ;
}

void map_body_dump(char map[HEIGHT][LENGTH], int index) {
    for (int i = index; i > 2; i--) {
        for(int j = 1; j < LENGTH - 1; j++) {
            map[i][j] = map[i - 1][j];
        }
    }
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


int main() {
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

    char object = 'T';
    int cordX = (LENGTH - 1) / 2;
    int cordY = 1;
    map[cordY][cordX] = object;

    enable_nonblock_mode();
    
    while (1) {
        if (map[cordY + 1][cordX] == object) {
            system("clear");
            map_print(map);
            printf("      GAME OVER\n");
            return 0;
        }
        int count = 0;
        for (int i = 1; i < HEIGHT - 1; i++) {
            count = 0;
            for(int j = 1; j < LENGTH - 1; j++) {
                if (map[i][j] == object) {
                    count++;
                }
                if(count == 9) {
                    for (int j = 1; j < LENGTH - 1; j++) {
                        map[i][j] = ' ';
                    }
                    map_body_dump(map, i);
                    score++;
                }
            }
        }
        system("clear");
        map_print(map);
        usleep(200000);

        for (int i = 1; map[cordY + 1][cordX] != '#' && map[cordY + 1][cordX] != object; i++) {
            char ch;
            read(STDIN_FILENO, &ch, 1);
            if (ch == 'q') {
                return 0; 
            }
            if (ch == 'a' && cordX - 1 != 0) {
                map[cordY][cordX] = ' ';
                cordX--;
                ch = 0;
                map[cordY][cordX] = object;
            }
            if (ch == 'd' && cordX + 1 != LENGTH - 1) {
                map[cordY][cordX] = ' ';
                cordX++;
                ch = 0;
                map[cordY][cordX] = object;
            }
            system("clear");
            map[cordY][cordX] = ' ';
            cordY++;
            map[cordY][cordX] = object;
            map_print(map);
            usleep(5000);
        }
        cordY = 1;
        map[cordY][cordX] = object;
    }
}
