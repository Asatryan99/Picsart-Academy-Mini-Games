#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

bool word_checker (const char* str, int size){
    for (int i = 0; i < size; i++) {
        if (str[i] == '*') {
            return false;
        }
    }
    return true;
}

int main ()
{
    printf("\t\n\033[0;32mWELLCOME TO HANDMAN\033[0m\n\nYou need to guess the word\n\n\033[0;32mPress ENTER to continue\033[0m\n");
    char start;
    scanf("%c",&start);

    const char word_list[6][13] = {"apple","bitcoin","piano","burger","picsart","interstellar"};
    const char clue_list[6][100] = {"This is a fruit, and this is also a logo","This is related to crypto currency","Musical instrument","Unhealthy but tasty food","Best Academy","Best Chris Nollan movie"};
next:    
    srand(time(NULL));
    int random = 1 + rand() % 5;
    char main_word[15] = {};
    char clue[100] = {};
    strcpy(main_word, word_list[random]);
    strcpy(clue,clue_list[random]);
    int wordsize = strlen(main_word);
    char* hidden_word = (char*)calloc(sizeof(char),wordsize);
    for (int i = 0; i < wordsize; i++) {
        hidden_word[i] = '*';
    }

    char letter;
    int hearts = 3;
    bool heart_flag = true;
    bool end = false;
    do {
        end = word_checker(hidden_word, wordsize);
        if (end) {
            system("clear");
            hidden_word[0] ^= 32;
            printf("\n\033[0;32mThat's right, it's a %s\033[0m\n", hidden_word);
            printf("\nWOOOW you're really smart !!!\n");

            char kay;
            printf("\nPress ENTER for Continue AND q for exit game\n");
            scanf("%c", &kay);
            if (kay == 'q') {
                free(hidden_word);           
                return 0;
            } else {
                goto next;
            }
        }
        system("clear");
        printf("\n\033[0;32m%s\033[0m\n\n\033[1;31mHearts : %d\033[0m\n", clue, hearts);
        printf("\n%s\n\n", hidden_word);
        printf("Enter letter: ");
        scanf("%c", &letter);
        getchar();
        for (int i = 0; i < wordsize; i++) {
            if (letter == main_word[i]) {
                hidden_word[i] = main_word[i];
                heart_flag = false;
            }
        }
        if (heart_flag) {
            hearts--;
            if (hearts == 0) {
                system("clear");
                printf("\n\033[1;31mYou lose, try again\n\033[0m");
                return -1;
            }
        }
        heart_flag = true;
    } while (!end);
}
