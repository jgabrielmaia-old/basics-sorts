#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Read musics from given CSV source 
void readMusicsFromCSV(char* filepath, Music* arr_musics, int take);
void readFromFile(char* filepath);
int writeMusicsToCSV(char* filepath, Music* arr_musics, int size);

static char* getfield(char* line, int num);

void readMusicsFromCSV(char* filepath, Music* arr_musics, int take)
{
    int m = 0;

    FILE* stream = fopen(filepath, "r");
    
    char line[1024];
    
    //Skip First line
    fgets(line, sizeof(line), stream);

    while (fgets(line, 1024, stream) && m < take)
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

int writeMusicsToCSV(char* filepath, Music* arr_musics, int size) 
{
    FILE * fp;
    int i;
    /* open the file for writing*/
    fp = fopen (filepath, "w");

    fprintf (fp, "id,name,artists\n");

    /* write 10 lines of text into the file stream*/
    for(i = 1; i < size;i++)
    {
        fprintf (fp, "%s,%s,%s\n",arr_musics[i].Id,arr_musics[i].Name, arr_musics[i].Artists);
    }

    /* close the file*/  
    fclose (fp);
    return 0;
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