#include "echo_my.h"

int echo_my(char ** args)
{
  if(args==NULL)
  {
    printf("\n");
    return 1;
  }
  for(int i=1; args[i]; i++)
    printf("%s ",args[i]);
  printf("\n");
  return 1;
}
