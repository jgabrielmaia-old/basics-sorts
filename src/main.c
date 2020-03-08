#include <stdlib.h>
#include "sort.h"

int main() 
{
    // size = 8 + offset = 1
    char toSort[9] = {'C','B','A','H','E','F','G','D'};

    MergeSort(toSort, 8);

    printStr(toSort);

    return 0;
}