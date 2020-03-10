#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct music
{
    char* Id;
    char* Name;
    char* Artists;
} music;

void printMusics(music* arr_musics, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("ID: %s\n",arr_musics[i].Id);
        printf("Name: %s\n",arr_musics[i].Name);
        printf("Artists: %s\n",arr_musics[i].Artists);
        printf("\n");
    }
    
}