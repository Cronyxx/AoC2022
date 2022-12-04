#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 10

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
    unsigned int calories = 0;

    while(fgets(buf, MAX_LENGTH, fp)) {

    	if (!strcmp(buf, "\n")) {
    		if (calories > maxCalories) {
    			maxCalories = calories;
    		}
    		calories = 0;
    	} else {
			calories += atoi(buf);
    	}
    }

    printf("The answer is %u \n", maxCalories);
}