#include <stdlib.h>
#include "sort.h"

int main() 
{
    // size = 8 + offset = 1
    char toSort[9] = {'C','B','A','H','E','F','G','D'};
    char toSort2[9] = {'Z','B','A','H','E','F','G','D'};

    MergeSort(toSort, 8);

    InsertionSort(toSort2, 8);

    printStr(toSort);
    printStr(toSort2);
    return 0;
}