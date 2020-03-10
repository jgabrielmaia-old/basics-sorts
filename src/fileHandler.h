#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFromFile(char* filepath);
void writeToFile(char* filepath);

static char* getfield(char* line, int num);

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

    for(tok = strtok(line, ","); tok != NULL; tok = strtok(NULL, ","))
    {
        printf("Count: %d", count);
        if (count++ == num)
            return tok;
    }
}