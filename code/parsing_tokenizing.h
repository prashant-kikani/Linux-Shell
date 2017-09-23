#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "global_vars.h"

char * getline_my();
char** get_tokens(char * line, char * delim, int ONE_SIZE);
int checkForBackground(char ** args);
