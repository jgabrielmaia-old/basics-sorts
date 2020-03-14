#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define strtok_r(s,d,p) strtok_s(s,d,p)
#endif


// Read musics from given CSV source 
void readMusicsFromCSV(char* filepath, Music* arr_musics, int take);
void readFromFile(char* filepath);
int writeMusicsToCSV(char* filepath, Music* arr_musics, int size);
char* replace_char(char* str, char find, char replace);
char *trimwhitespace(char *str);

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
        arr_musics[m].Id = getfield(line, 1);
        arr_musics[m].Name = getfield(line, 2);
        arr_musics[m].Artists = getfield(line, 3);

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
        printf("Id: %s\n", getfield(line, 1));
        printf("Name: %s\n", getfield(line, 2));
        printf("Artists: %s\n", getfield(line, 3));
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
    int count = 1;
    char* nextToken1 = NULL;
    char* nextToken2 = NULL;
    char* tok = strtok_s(_strdup(line), ",", &nextToken1);
    char* tok2 = strtok_s(_strdup(line), "\"", &nextToken2);

    char* finalToken = tok;

    while (count < num)
    {
        char* token = NULL;
        if (tok != NULL) 
        {
            token = strtok_r(NULL, ",", &nextToken1);
            if (token != NULL)
            {
                finalToken = token;
            }
        }
        if (tok2 != NULL) 
        {
            token = strtok_r(NULL, "\"", &nextToken2);
            if (token != NULL)
            {
                finalToken = token;
                nextToken1 = nextToken2;
            }
        }
        count++;
    }

    finalToken = replace_char(finalToken, ',', ' ');
    finalToken = trimwhitespace(finalToken);
    return finalToken;
}

char* replace_char(char* str, char find, char replace) 
{
    char* current_pos = strchr(str, find);
    while (current_pos) {
        *current_pos = replace;
        current_pos = strchr(current_pos, find);
    }
    return str;
}

char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}