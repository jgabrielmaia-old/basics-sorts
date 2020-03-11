#include <stdlib.h>
#include "music.h"
#include "sort.h"
#include "fileHandler.h"

int main() 
{
    Music* arr_musics = (Music*) calloc(100, sizeof(Music));
    readMusicsFromFile("../data/top2018.csv", arr_musics, 10);
    InsertionSortMusicsByName(arr_musics, 10);
    return 0;
}