#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readMusicsFromFile(char* filepath, music* arr_musics);
void readFromFile(char* filepath);
void writeToFile(char* filepath);

static char* getfield(char* line, int num);

void readMusicsFromFile(char* filepath, music* arr_musics)
{
    int m = 0;

    FILE* stream = fopen(filepath, "r");
    
    char line[1024];
    
    //Skip First line
    fgets(line, sizeof(line), stream);

    while (fgets(line, 1024, stream) && m < 100)
    {
        arr_musics[m].Id = getfield(line, 0);
        arr_musics[m].Name = getfield(line, 1);
        arr_musics[m].Artists = getfield(line, 2);

        m++;
    }
}

void readFromFile(char* filepath)
{
    FILE* stream = fopen(filepath, "r");
    
    char line[1024];
    
    //Skip First line
    fgets(line, sizeof(line), stream);

    while (fgets(line, 1024, stream))
    {
        printf("Id: %s\n", getfield(line, 0));
        printf("Name: %s\n", getfield(line, 1));
        printf("Artists: %s\n", getfield(line, 2));
        printf("\n");
    }

}

static char* getfield(char* line, int num)
{
    char* tok;
    int count = 0;
    char* tmp = strdup(line);
    
    for(tok = strtok(tmp, ","); tok != NULL; tok = strtok(NULL, ",\n"))
    {
        if (count++ == num)
            return tok;
    }
}