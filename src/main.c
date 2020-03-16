#include <stdlib.h>
#include "sort.h"
#include "random.h"
#include "utils.h"
#include "timer.h"

int main() 
{
    int size = 9;

    int* toSort = (int*) calloc (sizeof(int), size);
    toSort = getManyRandom(toSort, size);

    timer(MergeSort, "MergeSort", toSort, size);
    printIntArr(toSort, size);
    
    timer(InsertionSort, "InsertionSort", toSort, size);
    printIntArr(toSort, size);
    
    timer(BubbleSort, "InsertionSort", toSort, size);
    printIntArr(toSort, size);
    
    timer(SelectionSort, "SelectionSort", toSort, size);
    printIntArr(toSort, size);
    return 0;
}