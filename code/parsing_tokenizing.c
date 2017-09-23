#include "parsing_tokenizing.h"

char * getline_my()
{
  int bsz = BUFF_SIZE;
  int pos = 0;
  int c;
  char * line = malloc(sizeof(char)*BUFF_SIZE);
  if(!line)
  {
    fprintf(stderr, "%s\n", "Allocation error");
    exit(EXIT_FAILURE);
  }
  while(1)
  {
    c = getchar();
    if(c=='\n' || c==EOF)
    {
      line[pos++]='\0';
      return line;
    }
    else
      line[pos++] = c;

    if(pos>=bsz)
    {
      bsz += BUFF_SIZE;
      line = realloc(line, bsz);
      if(!line)
      {
        fprintf(stderr, "%s\n", "Allocation error");
        exit(EXIT_FAILURE);
      }
    }
  }
}

char** get_tokens(char * line, char * delim, int ONE_SIZE)
{
  if(line==NULL || line[0]=='\0' || delim == NULL)return NULL;

  int pos = 0;
  int tok_bsz = ONE_SIZE;
  char ** tokens_arr = malloc(sizeof(char*)*tok_bsz);
  char * token;
  if(!tokens_arr)
  {
    fprintf(stderr, "%s\n", "Allocation error");
    exit(EXIT_FAILURE);
  }
  token = strtok(line, delim);
  while(token)
  {
    tokens_arr[pos++] = token;
    if(pos>=ONE_SIZE)
    {
      tok_bsz += ONE_SIZE;
      tokens_arr = realloc(tokens_arr, sizeof(char*)*tok_bsz);
      if(!tokens_arr)
      {
        fprintf(stderr, "%s\n", "Allocation error");
        exit(EXIT_FAILURE);
      }
    }
    token = strtok(NULL, delim);
  }
  tokens_arr[pos++] = NULL;
  return tokens_arr;
}

int checkForBackground(char ** args)
{
  if(args == NULL || args[0] == NULL)return 0;
  int l = strlen(args[0]);

  if(args[0][l-1]=='&')
  {
    args[1] = NULL;
    args[0][l-1]='\0';
    return 1;
  }
  else
  {
    int i;
    for(i=0; args[i+1]; i++);
    if((strcmp("&", args[i]))==0)
    {
      args[i]=NULL;
      return 1;
    }
    else
      return 0;
  }
}
