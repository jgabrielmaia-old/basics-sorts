#include<stdio.h>

//Sorts
static void BubbleSort (int toSort[], int size);
static void InsertionSort (int toSort[], int size);
static void SelectionSort (int toSort[], int size);
static void MergeSort (int toSort[], int size);

void Split (int toSort[], int first, int last);
void Merge (int toSort[], int first, int mid, int last);
void swapint (int *a, int *b);
void swapInt (int *a, int *b);
void printIntArr (int* toPrint, int size);

static void BubbleSort (int toSort[], int size)
{
    int i,j;
    
    for(i = 0; i < size - 1; i++)
    {
        for(j = 0; j < size - i - 1; j++)
        {
            if(toSort[j] > toSort[j+1])
            {
                swapint(&toSort[j], &toSort[j+1]);
            }                
        }   
    }
}

static void SelectionSort (int toSort[], int size)
{
    int i,j, min;
    
    for(i = 0; i < (size - 1); i++)
    {
        min = i;
        for(j = i+1; j < size; j++)
            if(toSort[j] < toSort[min])
                min = j;  

        if(i != min)
            swapint(&toSort[i], &toSort[min]);
    }
}

static void InsertionSort (int toSort[], int size)
{
    int i,j;
    int key;
    
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

void swapint(int *a, int *b)
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void swapInt(int *a, int *b)
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

static void MergeSort (int toSort[], int size)
{
    Split(toSort, 0, size);
}

void Split(int toSort[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        Split(toSort, first, mid); 
        Split(toSort, mid+1, last); 
        Merge(toSort, first, mid, last);
    }
}

void Merge(int toSort[], int first, int mid, int last)
{
    int i = first, 
        j = mid + 1, 
        index = 0;

    int aux[(last-first)+1];

    while(i <= mid && j <= last)
    {
        if(toSort[i] < toSort[j])
            aux[index++] = toSort[i++];
        else
            aux[index++] = toSort[j++];           
    }
    
    while(i <= mid)
        aux[index++] = toSort[i++];
    
    while(j <= last)
        aux[index++] = toSort[j++];


    int l = 0;
    for(l = first; l <= last; l++)
        toSort[l] = aux[l-first];
}

void printIntArr(int* toPrint, int size)
{
    printf("\nRESULT:");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", toPrint[i]);
    }
    printf("\n");    
}