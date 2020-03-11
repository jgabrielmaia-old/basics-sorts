#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct music
{
    char* Id;
    char* Name;
    char* Artists;
} Music;

void printMusics(Music* arr_musics, int size);
void printMusicNames(Music* arr_musics, int size);

void printMusics(Music* arr_musics, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("ID: %s\n",arr_musics[i].Id);
        printf("Name: %s\n",arr_musics[i].Name);
        printf("Artists: %s\n",arr_musics[i].Artists);
        printf("\n");
    }
}

void printMusicNames(Music* arr_musics, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s\n",arr_musics[i].Name);
    }
}