#include<stdio.h>

void printIntArr (int* toPrint, int size);

void printIntArr(int* toPrint, int size)
{
    printf("\nRESULT:");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", toPrint[i]);
    }
    printf("\n");    
}