#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 5
#define ROCK 1
#define PAPER 2
#define SCISSORS 3
#define LOSE 0
#define DRAW 3
#define WIN 6

unsigned int mapCharToInt (char *gameInput) {
    switch(*gameInput) 
    {
        case 'A':
        case 'X':
            return ROCK;
        case 'B':
        case 'Y':
            return PAPER;
        case 'C':
        case 'Z':
            return SCISSORS;
        default:
            printf("Error occured during mapping");
            return -1;
    }
}

int main () {
	FILE *fp;
	unsigned int maxCalories = 0;
	
	fp = fopen("./input.txt", "r");

	// Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file!");
        return 0;
    }

    char buf[MAX_LENGTH];
    unsigned int points = 0;

    while(fgets(buf, MAX_LENGTH, fp)) {
        char *opponent = strtok(buf, " ");
        char *player = strtok(NULL, " ");
    	
        unsigned int opponentHand = mapCharToInt(opponent);
        unsigned int playerHand = mapCharToInt(player);

        points += playerHand;

        if (opponentHand == playerHand) {
            points += DRAW;
        } else if (opponentHand == 1 && playerHand == 3) {
            points += LOSE; 
        } else if (opponentHand == 3 && playerHand == 1) {
            points += WIN;
        } else if (opponentHand > playerHand) {
            points += LOSE;
        } else if (opponentHand < playerHand) {
            points += WIN;
        }
    }

    printf("The answer is %u \n", points);
}