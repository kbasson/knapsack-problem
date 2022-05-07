knapsack: knapsack.o helpers.o
	clang -Wall -pedantic -std=c99 knapsack.o helpers.o -o knapsack

knapsack.o: knapsack.c knapsack.h
	clang -Wall -pedantic -std=c99 -c knapsack.c -o knapsack.o

helpers.o: helpers.c knapsack.h
	clang -Wall -pedantic -std=c99 -c helpers.c -o helpers.o

clean:
	rm *.o
