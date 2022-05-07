/*
    Name: Karanvir Basson
    Title: Knapsack Problem Dynamic Programming Algorithm
    Date: 05-06-2022
*/

#include "knapsack.h"

void solveKnapsackSubProblem(Cell dynamicProgrammingTable[NUM_ITEMS + 1][CAPACITY + 1], Item items[NUM_ITEMS], int numItems, int capacity) { //Given a knapsack subproblem, solve it and update dynamic programming table

    for (int i = 0; i < NUM_ITEMS; i++) { //Initialize Cell subarray
        
        dynamicProgrammingTable[numItems][capacity].itemIndices[i] = -1;

    }

    if (numItems == 0 || capacity == 0) { //If "empty" subproblem, initialize cell to zeroes

        dynamicProgrammingTable[numItems][capacity].totalWeight = 0;
        dynamicProgrammingTable[numItems][capacity].totalValue = 0;

    } else {

        if (items[numItems - 1].weight > capacity) { //If new item doesn't fit current knapsack capacity

            //COPY OPTIMIZED SOLUTION FROM CELL ABOVE

            for (int i = 0; i < NUM_ITEMS; i++) {

                dynamicProgrammingTable[numItems][capacity].itemIndices[i] = dynamicProgrammingTable[numItems - 1][capacity].itemIndices[i];

            }

            dynamicProgrammingTable[numItems][capacity].totalWeight = dynamicProgrammingTable[numItems - 1][capacity].totalWeight;
            dynamicProgrammingTable[numItems][capacity].totalValue = dynamicProgrammingTable[numItems - 1][capacity].totalValue;

        } else { //If new item fits current knapsack capacity

            int newWeight = items[numItems - 1].weight + dynamicProgrammingTable[numItems - 1][capacity - items[numItems - 1].weight].totalWeight;
            int newValue = items[numItems - 1].value + dynamicProgrammingTable[numItems - 1][capacity - items[numItems - 1].weight].totalValue;

            if (newValue > dynamicProgrammingTable[numItems - 1][capacity].totalValue) { //If adding new item yields more value than optimized solution from cell above

                //COPY OPTIMIZED SOLUTION FROM CELL IN ABOVE ROW AND APPEND NEW ITEM

                for (int i = 0; i < NUM_ITEMS; i++) {

                    dynamicProgrammingTable[numItems][capacity].itemIndices[i] = dynamicProgrammingTable[numItems - 1][capacity - items[numItems - 1].weight].itemIndices[i];

                    if (dynamicProgrammingTable[numItems][capacity].itemIndices[i] == -1) {

                        dynamicProgrammingTable[numItems][capacity].itemIndices[i] = numItems - 1;
                        break;

                    }

                }

                dynamicProgrammingTable[numItems][capacity].totalWeight = newWeight;
                dynamicProgrammingTable[numItems][capacity].totalValue = newValue;

            } else { //If adding new item yields less value than optimized solution from cell above

                //COPY OPTIMIZED SOLUTION FROM CELL ABOVE

                for (int i = 0; i < NUM_ITEMS; i++) {

                    dynamicProgrammingTable[numItems][capacity].itemIndices[i] = dynamicProgrammingTable[numItems - 1][capacity].itemIndices[i];

                }

                dynamicProgrammingTable[numItems][capacity].totalWeight = dynamicProgrammingTable[numItems - 1][capacity].totalWeight;
                dynamicProgrammingTable[numItems][capacity].totalValue = dynamicProgrammingTable[numItems - 1][capacity].totalValue;

            }

        }

    }

    //CREATE FORMATTED SUBARRAY STRING

    char text[numItems * 10];
    strcpy(text, "{");

    for (int i = 0; i < NUM_ITEMS; i++) {

        if (dynamicProgrammingTable[numItems][capacity].itemIndices[i] != -1) {

            char num[10];
            sprintf(num, "%d ", dynamicProgrammingTable[numItems][capacity].itemIndices[i] + 1);
            strcat(text, num);

        }

    }

    if (strlen(text) - 1 > 0) text[strlen(text) - 1] = '}';
    else strcat(text, "}");

    //PRINT OPTIMIZED SUBPROBLEM SOLUTION RESULTS
    printf("numItems = %d, capacity = %d\n", numItems, capacity);
    printf("items = %s\n", text);
    printf("totalWeight = %d, totalValue = %d\n\n", dynamicProgrammingTable[numItems][capacity].totalWeight, dynamicProgrammingTable[numItems][capacity].totalValue);

}
