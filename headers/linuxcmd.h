#ifndef LINUXCMD_H_INCLUDED
#define LINUXCMD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_BUFF_SET 255
#define LINES 100

typedef struct 
{
    char *token;
    int related_Line;
} GrepResult;

GrepResult grep(char fileName[], char text[]);

#endif