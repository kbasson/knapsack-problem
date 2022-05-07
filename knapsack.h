/*
    Name: Karanvir Basson
    Title: Knapsack Problem Dynamic Programming Algorithm
    Date: 05-06-2022
*/

//INCLUDE HEADER FILES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ITEMS 4 //Total number of items
#define CAPACITY 5 //Max weight allowed in Knapsack
#define FILENAME "items.txt" //Name of file containing items
#define STR_SIZE 20 //Num chars in string, used when reading text from file

typedef struct { //Struct representing an item

    int weight;
    int value;
    int inKnapsack;

} Item;

typedef struct { //Struct representing a cell in the dynamic programming table

    int itemIndices[NUM_ITEMS];
    int totalWeight;
    int totalValue;

} Cell;

void solveKnapsackSubProblem(Cell dynamicProgrammingTable[NUM_ITEMS + 1][CAPACITY + 1], Item items[NUM_ITEMS], int numItems, int capacity); //Given a knapsack subproblem, solve it and update dynamic programming table
