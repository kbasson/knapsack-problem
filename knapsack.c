/*
    Name: Karanvir Basson
    Title: Knapsack Problem Dynamic Programming Algorithm
    Date: 05-06-2022
*/

#include "knapsack.h"

int main() {

    Item items[NUM_ITEMS];

    FILE* file = fopen(FILENAME, "r"); //Open file for reading

    if (file == NULL) { //If file doesn't exist

        printf("%s not found!\n", FILENAME);
        return 0;

    }

    char text[STR_SIZE];
    int c = 0;

    while (fgets(text, STR_SIZE, file)) { //Read item from file

        char* token = strtok(text, " \n"); //Get current item weight as string
        items[c].weight = atoi(token); //Store weight in item struct

        token = strtok(NULL, " \n"); //Get current item value as string
        items[c].value = atoi(token); //Store value in item struct

        //printf("Weight = %d, Value = %d\n", items[c].weight, items[c].value);

        c++;

    }

    fclose(file); //Close file ptr

    Cell dynamicProgrammingTable[NUM_ITEMS + 1][CAPACITY + 1];

    for (int j = 0; j < CAPACITY + 1; j++) { //For each column

        for (int i = 0; i < NUM_ITEMS + 1; i++) { //For each row

            solveKnapsackSubProblem(dynamicProgrammingTable, items, i, j); //Solve current knapsack sub problem for capacity j and subarray of first i items

        }

    }

    return 1;

}
