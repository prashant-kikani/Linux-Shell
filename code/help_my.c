#include "help_my.h"

int help_my(char ** args)
{
  for(int i=0; shell_command_str[i]; i++)
    printf("%s\n",shell_command_str[i]);
  return 1;
}
