#include <stdio.h>
#include "header.h"

void remove_comments(FILE *fp, FILE *out)
{
    int ch, next;

    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == '/')
        {
            next = fgetc(fp);

            if(next == '/')
            {
                while((ch = fgetc(fp)) != EOF && ch != '\n');
                fputc('\n', out);
            }
            else if(next == '*')
            {
                while((ch = fgetc(fp)) != EOF)
                {
                    if(ch == '*')
                    {
                        next = fgetc(fp);

                        if(next == '/')
                            break;
                        else
                            ungetc(next, fp);
                    }
                }
            }
            else
            {
                fputc('/', out);
                if(next != EOF)
                    ungetc(next, fp);
            }
        }
        else
        {
            fputc(ch, out);
        }
    }
}
