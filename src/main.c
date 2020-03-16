#include <stdlib.h>
#include "sort.h"
#include "random.h"

int main() 
{
    int numberCount = 9;

    int* toSort = (int*) calloc (sizeof(int), numberCount);
    toSort = getManyRandom(toSort, numberCount);

    printf("\nMergeSort:");
    MergeSort(toSort, numberCount);
    printIntArr(toSort, numberCount);
    
    printf("\nInsertionSort:");
    InsertionSort(toSort, numberCount);
    printIntArr(toSort, numberCount);
    
    printf("\nBubbleSort:");
    BubbleSort(toSort, numberCount);
    printIntArr(toSort, numberCount);
    
    printf("\nSelectionSort:");
    SelectionSort(toSort, numberCount);
    printIntArr(toSort, numberCount);
    return 0;
}