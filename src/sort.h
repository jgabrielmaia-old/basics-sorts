#include <stdio.h>
#include <strings.h>

//Sorts
static void BubbleSort (char toSort[], int size);
static void InsertionSort (char toSort[], int size);
static void SelectionSort (char toSort[], int size);

static void MergeSort (char toSort[], int size);
void Split (char toSort[], int first, int last);
void Merge (char toSort[], int first, int mid, int last);


static void InsertionSortMusicsByName (Music* arr_musics, int size);
static void MergeSortMusicsByName (Music toSort[], int size);


void MSplit (Music toSort[], int first, int last);
void MMerge (Music toSort[], int first, int mid, int last);
void swapChar (char *a, char *b);
void swapInt (int *a, int *b);
void printStr (char* toPrint);

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
    int i,j;
    char key;
    
    for(i = 1; i < size; i++)
    {
        key = toSort[i];
        j = i - 1;
        while(j >= 0 && toSort[j] > key)
        {
            toSort[j+1] = toSort[j];
            j--;
        }

        toSort[j+1] = key;
    }
}

static void InsertionSortMusicsByName (Music* arr_musics, int size)
{
    int i,j;
    Music key;

    for(i = 1; i < size; i++)
    {
        key = arr_musics[i];
        j = i - 1;

        while(j >= 0 && strcasecmp(arr_musics[j].Name, key.Name) > 0)
        {
            arr_musics[j+1] = arr_musics[j];
            j--;
        }

        arr_musics[j+1]= key;
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

static void MergeSort (char toSort[], int size)
{
    Split(toSort, 0, size - 1);
}

void Split(char toSort[], int first, int last)
{
    printf("First: %d, Last: %d\n", first,last);

    if (first < last)
    {
        int mid = (first + last) / 2;
        Split(toSort, first, mid); 
        Split(toSort, mid+1, last); 
        Merge(toSort, first, mid, last);
    }
}

void Merge(char toSort[], int first, int mid, int last)
{
    int i = first, 
        j = mid + 1, 
        index = 0;

    char aux[(last-first)+1];

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

static void MergeSortMusicsByName (Music toSort[], int size)
{
    MSplit(toSort, 0, size - 1);
}

void MSplit(Music toSort[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        MSplit(toSort, first, mid); 
        MSplit(toSort, mid+1, last); 
        MMerge(toSort, first, mid, last);
    }
}

void MMerge(Music toSort[], int first, int mid, int last)
{
    int i = first, 
        j = mid + 1, 
        index = 0;

    Music aux[(last-first)+1];

    while(i <= mid && j <= last)
    {
        if(strcasecmp(toSort[i].Name, toSort[j].Name) < 0)
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

void printStr(char* toPrint)
{
    printf("\nRESULT: %s\n\n", toPrint);
}