#include<stdio.h>

//Sorts
static void BubbleSort (char toSort[], int size);
static void InsertionSort (char toSort[], int size);
static void SelectionSort (char toSort[], int size);

//Utils
void swapChar(char *a, char *b);
void swapInt(int *a, int *b);
void printStr(char* toPrint);

static void BubbleSort (char toSort[], int size)
{
    int i,j;
    
    for(i = 0; i < size - 1; i++)
    {
        for(j = 0; j < size - i - 1; j++)
        {
            if(toSort[j] > toSort[j+1])
            {
                swapChar(&toSort[j], &toSort[j+1]);
                printStr(toSort);
            }                
        }   
    }
}

static void SelectionSort (char toSort[], int size)
{
    int i,j, min;
    
    for(i = 0; i < (size - 1); i++)
    {
        min = i;
        for(j = i+1; j < size; j++)
            if(toSort[j] < toSort[min])
                min = j;  

        if(i != min)
            swapChar(&toSort[i], &toSort[min]);
    }
}

static void InsertionSort (char toSort[], int size)
{
    int i,j, key;
    
    for(i = 1; i < size; i++)
    {
        key = toSort[i];
        j = i - 1;
        while((j >= 0) && (toSort[j] > key))
        {
            toSort[j+1] =toSort[j];
            j--;
        }

        toSort[j+1] = key;
    }
}

void swapChar(char *a, char *b)
{ 
    char temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void swapInt(int *a, int *b)
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

void printStr(char* toPrint)
{
    printf("RESULT: %s\n", toPrint);
}