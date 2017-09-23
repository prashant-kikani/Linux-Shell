#include "cd_my.h"

int cd_my(char ** args)
{
  if(args[1]==NULL)
  {
    args[1] = shellDir;
    return cd_my(args);
  }
  else if(args[1][0]=='~')
  {
    char * temp = malloc(BUFF_SIZE*sizeof(char));
    strcpy(temp, shellDir);
    strcpy(temp+strlen(temp), args[1]+1);
    args[1] = temp;
    return cd_my(args);
  }
  else
  {
    if(chdir(args[1]) != 0)
    {
      perror("error ");
      return 1;
    }
  }
  char * current = malloc(BUFF_SIZE*sizeof(char));
  getcwd(current, BUFF_SIZE-1);
  for(int i=0; ; i++)
  {
    if(shellDir[i]=='\0' && current[i]=='\0')
    {
      curDir[0] = '~';
      curDir[1] = '\0';
      free(current);
      break;
    }
    else if(shellDir[i]=='\0')
    {
      curDir[0] = '~';
      strcpy(curDir+1, current+i);
      free(current);
      break;
    }
    else if(current[i]=='\0')
    {
      char * temp = curDir;
      curDir = current;
      free(temp);
      break;
    }
  }
  return 1;
}
