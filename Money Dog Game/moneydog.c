#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <time.h>
#include <termios.h>

#define MAP_SIZE 13

int setEchoMode (bool enable) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ ICANON;
    if (enable) {
        newt.c_lflag |= ECHO;
    }
    else {
        newt.c_lflag &= ~ECHO;
    }
    tcsetattr(STDIN_FILENO,TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO,TCSANOW, &oldt);
    return ch;
}

int getch () {
    return setEchoMode(false);
}

void red () {
  printf("\033[1;31m");
}
void blue () {
  printf("\033[0;34m");
}
void green () {
  printf("\033[0;32m");
}
void yellow () {
  printf("\033[0;33m");
}
void reset () {
  printf("\033[0m");
}

void print_matrix (char matrix[][MAP_SIZE]) {

    for (int row = 0; row <  MAP_SIZE; row++) {
        for (int col = 0; col < MAP_SIZE; col++) {
            if (matrix[row][col] == '$') {
                green();
            } else if (matrix[row][col] == '#') {
                red();
            } else if (matrix[row][col] == '@') {
                yellow();
            } else { 
                reset();
        }
        printf("%c ", matrix[row][col]);
        }
        printf("\n");
    }
    reset();
}

int main () 
{
    system("clear");
    printf("\033[0;31mWELCOME TO MONEY DOG \033[0m\n\nCONTROL BUTTONS\n\n\033[0;32m W is: UP\n S is: DOWN \n A is: LEFT \n D is: RIGHT \033[1;31m \n\nPress ENTER to continue \033[0m");
    char start = 0;
    scanf("%c", &start);
    system("clear");
    char MAP [MAP_SIZE][MAP_SIZE];
    for (int row = 0; row <  MAP_SIZE; row++) {
        for (int col = 0; col < MAP_SIZE; col++) {
            if (row == 0 || col == 0 || row == (MAP_SIZE - 1) || col == (MAP_SIZE - 1)) {
                MAP[row][col] = '#';
            } else {
                MAP[row][col] = ' ';
            }
        }
    }

    int x = (MAP_SIZE - 1) / 2;
    int y = (MAP_SIZE - 1) / 2;
    MAP[x][y] = '@';

    int apple_x, apple_y;
    int money = 0;
    srand(time(0));
    apple_x = 1 + rand() % (MAP_SIZE - 2);
    apple_y = 1 + rand() % (MAP_SIZE - 2);
    MAP[apple_x][apple_y] = '$';
    printf("\t \033[0;32mBANK:%d$\033[0m\n\n", money);
    print_matrix(MAP);

    char kay;
    do {
        MAP[x][y] = ' ';
        kay = getch();
        if (kay == 'w' && (x - 1) != 0) x--;
        if (kay == 's' && (x + 1) != MAP_SIZE - 1) x++;
        if (kay == 'd' && (y + 1) != MAP_SIZE - 1) y++;
        if (kay == 'a' && (y - 1) != 0) y--;
        system("clear");
        MAP[x][y] = '@';
        if (x == apple_x && y == apple_y) {
            money += 100;
            apple_x = 1 + rand() % (MAP_SIZE - 2);
            apple_y = 1 + rand() % (MAP_SIZE - 2);
            MAP[apple_x][apple_y] = '$';
        }
        printf("\t \033[0;32mBANK:%d$\033[0m\n\n", money);
        print_matrix(MAP);

    } while (kay != 'q');
}