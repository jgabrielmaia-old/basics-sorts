#include <stdlib.h>
#include "sort.h"
#include "random.h"

int main() 
{
    int* toSort = (int*) calloc (sizeof(int), 9);
    toSort = getManyRandom(toSort, 9);

    MergeSort(toSort, 8);
    printIntArr(toSort, 8);
    
    InsertionSort(toSort, 8);
    printIntArr(toSort, 8);
    
    BubbleSort(toSort, 8);
    printIntArr(toSort, 8);
    
    SelectionSort(toSort, 8);
    printIntArr(toSort, 8);
    return 0;
}