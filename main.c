#include <stdio.h>
#include <string.h>
#include "header.h"

int main(int argc, char *argv[])
{
    FILE *fp, *out, *temp, *temp2;
    char output[100];
    char *p;

    if(argc != 2)
    {
        printf("Usage: ./myprocessor filename.c\n");
        return 1;
    }

    fp = fopen(argv[1], "r");

    if(fp == NULL)
    {
        printf("Input file not found\n");
        return 1;
    }

    strcpy(output, argv[1]);
    p = strrchr(output, '.');

    if(p != NULL)
        strcpy(p, ".i");
    else
        strcat(output, ".i");

    temp = fopen("temp.c", "w");

    if(temp == NULL)
    {
        fclose(fp);
        return 1;
    }

    remove_comments(fp, temp);

    fclose(fp);
    fclose(temp);

    temp = fopen("temp.c", "r");
    temp2 = fopen("temp2.c", "w");

    if(temp == NULL || temp2 == NULL)
        return 1;

    file_inclusion(temp, temp2);

    fclose(temp);
    fclose(temp2);

    temp2 = fopen("temp2.c", "r");
    out = fopen(output, "w");

    if(temp2 == NULL || out == NULL)
        return 1;

    macro_handler(temp2, out);

    fclose(temp2);
    fclose(out);

    remove("temp.c");
    remove("temp2.c");

    printf("Output file created: %s\n", output);

    return 0;
}
