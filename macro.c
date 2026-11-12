#include <stdio.h>
#include <string.h>
#include "header.h"

void macro_handler(FILE *fp, FILE *out)
{
    char line[500];
    char name[50], value[100];
    char macros[100][50], values[100][100];
    char word[100];
    int count = 0, i, j, k;

    while(fgets(line, sizeof(line), fp) != NULL)
    {
        if(strncmp(line, "#define", 7) == 0)
        {
            if(sscanf(line, "#define %s %[^\n]", name, value) == 2)
            {
                strcpy(macros[count], name);
                strcpy(values[count], value);
                count++;
            }
        }
        else
        {
            i = 0;

            while(line[i] != '\0')
            {
                if((line[i] >= 'A' && line[i] <= 'Z') ||
                   (line[i] >= 'a' && line[i] <= 'z') ||
                   line[i] == '_')
                {
                    j = 0;

                    while((line[i] >= 'A' && line[i] <= 'Z') ||
                          (line[i] >= 'a' && line[i] <= 'z') ||
                          (line[i] >= '0' && line[i] <= '9') ||
                          line[i] == '_')
                    {
                        word[j++] = line[i++];
                    }

                    word[j] = '\0';

                    for(k = 0; k < count; k++)
                    {
                        if(strcmp(word, macros[k]) == 0)
                            break;
                    }

                    if(k < count)
                        fputs(values[k], out);
                    else
                        fputs(word, out);
                }
                else
                {
                    fputc(line[i], out);
                    i++;
                }
            }
        }
    }
}
