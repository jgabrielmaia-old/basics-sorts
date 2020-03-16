#include <stdio.h>

void timer(void (*sorter)(), char* sorterName, int* toSort, int size);

void timer(void (*sorter)(), char* sorterName, int* toSort, int size) 
{
    double timeSpent = 0.0;

	clock_t begin = clock();

	sorter(toSort, size);

	clock_t end = clock();

    timeSpent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("%s: %f seconds", sorterName, timeSpent);
}