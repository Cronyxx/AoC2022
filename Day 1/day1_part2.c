#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LENGTH 10
#define LENGTH_TOP_CALORIES 3
#define NULL_VAlUE -1


int main () {
	FILE *fp;
	unsigned int topCalories[LENGTH_TOP_CALORIES] = {0, 0, 0};
	
	fp = fopen("./input.txt", "r");

	// Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file!");
        return 0;
    }

    char buf[MAX_LENGTH];
    unsigned int calories = 0;

    while(fgets(buf, MAX_LENGTH, fp)) {
    	if (!strcmp(buf, "\n")) {
            int counter = NULL_VAlUE;
            unsigned int currentCalories = UINT_MAX;
            for (int i = 0; i < LENGTH_TOP_CALORIES; i++) {
                // Find lowest top calories
                if (topCalories[i] < currentCalories) {
                    currentCalories = topCalories[i];
                    counter = i;
                }
            }
            if (currentCalories < calories) {
                topCalories[counter] = calories;
            }
    		calories = 0;
    	} else {
			calories += atoi(buf);
    	}
    }

    unsigned int answer = 0;
    for (int j = 0; j < LENGTH_TOP_CALORIES; j++) {
        answer += topCalories[j];
    }

    printf("The answer is %u \n", answer);
}