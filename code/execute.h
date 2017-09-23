#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<signal.h>
#include "global_vars.h"

int execute_system_command(char ** args, int background);
int execute_line(char ** args, int background);
