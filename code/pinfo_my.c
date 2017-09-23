#include "pinfo_my.h"

int pinfo_my(char ** args)
{
  if(args==NULL || args[1]==NULL)
  {
    fprintf(stderr, "need pid as argument\n");
    return 1;
  }
  char * path = malloc(sizeof(char)*BUFF_SIZE);
  char * out = malloc(sizeof(char)*BUFF_SIZE);
  char * path_status = malloc(sizeof(char)*BUFF_SIZE);
  strcpy(path, "/proc/");
  strcat(path, args[1]);
  strcpy(path_status, path);
  strcat(path, "/exe");
  strcat(path_status, "/status");
  readlink(path, out, BUFF_SIZE-1);
  printf("Path: %s\n",out);

  FILE * fp = fopen(path_status, "r");
  int st = 0;
  size_t sz = BUFF_SIZE;
  do
  {
    if(getline(&path, &sz, fp)==-1)
    {
        perror("");
        break;
    }
    st++;
    if(st==2 || st==5 || st==17)
      printf("%s",path);
  }while(st<17);
  fclose(fp);
  free(path);
  free(path_status);
  free(out);
  return 1;
}
