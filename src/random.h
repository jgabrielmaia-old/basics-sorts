#include <time.h>
#include <stdlib.h>

int getRandom();
int* getManyRandom(int* arr, int limit);

int getRandom()
{
    return rand();
};

int* getManyRandom(int* arr, int limit)
{
    for (size_t i = 0; i <= limit; i++)
    {
        arr[i] = getRandom();
    }

    return arr;    
}