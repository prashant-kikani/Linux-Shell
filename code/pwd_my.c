#include "pwd_my.h"

int pwd_my(char ** args)
{
  if(args==NULL)return 1;
  char * current = malloc(BUFF_SIZE * sizeof(char));
  if(getcwd(current, BUFF_SIZE-1)==0)
    perror("error : ");
  else
    printf("%s\n", current);
  free(current);
  return 1;
}
