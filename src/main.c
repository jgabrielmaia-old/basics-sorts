#include <stdlib.h>
#include "music.h"
#include "sort.h"
#include "fileHandler.h"

int main() 
{
    //Allocate space for a hundred instances of Music
    Music* arr_musics_insert = (Music*) calloc(100, sizeof(Music));
    Music* arr_musics_merge = (Music*) calloc(100, sizeof(Music));

    printf("\nReading musics from file: %s\n", "../data/top2018.csv");
    // Read data from source file into Music array
    readMusicsFromCSV("../data/top2018.csv", arr_musics_insert, 100);
    
    //Copy the array for Merge and Insertion sorting
    arr_musics_merge = arr_musics_insert;
    
    //InsertionSort
    InsertionSortMusicsByName(arr_musics_insert, 100);
    printf("\nSorted Musics by Insertion:\n");
    printMusicNames(arr_musics_insert, 100);

    printf("\nSaving Musics on file for InsertionSort...\n");
    writeMusicsToCSV("../data/spotify_insertionsort.csv", arr_musics_insert, 100);
    printf("\nSaved!\n\n\n");
    
    //MergeSort
    MergeSortMusicsByName(arr_musics_merge, 10);
    printf("\nSorted Musics by MergeSort:\n");
    printMusicNames(arr_musics_merge, 10);

    printf("\nSaving Musics on file for MergeSort...\n");
    writeMusicsToCSV("../data/spotify_mergesort.csv",arr_musics_merge, 10);
    printf("\nSaved!\n\n\n");

    return 0;
}