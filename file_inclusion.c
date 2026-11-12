#include <stdio.h>
#include <string.h>
#include "header.h"

void file_inclusion(FILE *fp, FILE *out)
{
    char line[500];
    char filename[100];
    char path[200];
    char *p, *q;
    FILE *inc;

    while(fgets(line, sizeof(line), fp) != NULL)
    {
        if(strncmp(line, "#include", 8) == 0)
        {
            p = strchr(line, '"');

            if(p != NULL)
                q = strchr(p + 1, '"');
            else
            {
                p = strchr(line, '<');

                if(p != NULL)
                    q = strchr(p + 1, '>');
                else
                    q = NULL;
            }

            if(p != NULL && q != NULL)
            {
                strncpy(filename, p + 1, q - p - 1);
                filename[q - p - 1] = '\0';

                inc = fopen(filename, "r");

                if(inc == NULL)
                {
                    strcpy(path, "/usr/include/");
                    strcat(path, filename);
                    inc = fopen(path, "r");
                }

                if(inc != NULL)
                {
                    file_inclusion(inc, out);
                    fclose(inc);
                }
                else
                    fputs(line, out);
            }
            else
                fputs(line, out);
        }
        else
            fputs(line, out);
    }
}
