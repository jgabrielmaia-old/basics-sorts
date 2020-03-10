#include <stdlib.h>
#include "music.h"
#include "sort.h"
#include "fileHandler.h"

int main() 
{
    music* arr_musics = (music*) calloc(100, sizeof(music));
    readMusicsFromFile("../data/top2018.csv", arr_musics, 10);
    InsertionSortMusicsByName(arr_musics, 10);
    return 0;
}