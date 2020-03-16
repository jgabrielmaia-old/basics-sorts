#include <stdlib.h>
#include "sort.h"
#include "random.h"
#include "utils.h"

int main() 
{
    int size = 9;

    int* toSort = (int*) calloc (sizeof(int), size);
    toSort = getManyRandom(toSort, size);

    printf("\nMergeSort:");
    MergeSort(toSort, size);
    printIntArr(toSort, size);
    
    printf("\nInsertionSort:");
    InsertionSort(toSort, size);
    printIntArr(toSort, size);
    
    printf("\nBubbleSort:");
    BubbleSort(toSort, size);
    printIntArr(toSort, size);
    
    printf("\nSelectionSort:");
    SelectionSort(toSort, size);
    printIntArr(toSort, size);
    return 0;
}