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

unsigned int mapCharToHand (char *gameInput) {
    switch(*gameInput) 
    {
        case 'A':
            return ROCK;
        case 'B':
            return PAPER;
        case 'C':
            return SCISSORS;
        default:
            printf("Error occured during mapping");
            return -1;
    }
}

unsigned int mapCharToOutcome (char *gameInput) {
    switch(*gameInput) 
    {
        case 'X':
            return LOSE;
        case 'Y':
            return DRAW;
        case 'Z':
            return WIN;
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
        char *outcomeChar = strtok(NULL, " ");
    	
        unsigned int opponentHand = mapCharToHand(opponent);
        unsigned int outcome = mapCharToOutcome(outcomeChar);

        points += outcome;

        if (outcome == DRAW) {
            points += opponentHand;
        } else if (outcome == WIN) {
            if (opponentHand == SCISSORS) {
                points += ROCK;
            } else {
                points += opponentHand + 1;
            }
        } else if (outcome == LOSE) {
            if (opponentHand == ROCK) {
                points += SCISSORS;
            } else {
                points += opponentHand - 1;
            }
        }
    }

    printf("The answer is %u \n", points);
}