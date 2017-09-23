#include "main.h"


void initialize_shell(char ** user, char ** host)
{
  *user = malloc(sizeof(char)*BUFF_SIZE);
  getlogin_r(*user, BUFF_SIZE);
  *host = malloc(sizeof(char)*BUFF_SIZE);
  FILE * fp = popen("lsb_release -ds", "r");
  fgets(*host, BUFF_SIZE, fp);

  int i;
  for(i=0; (*host)[i] != ' '; i++);
  (*host)[i] = '\0';
  pclose(fp);
  (*host)++;

  //strcpy(*host, "Fedora");
  shellDir = malloc(sizeof(char)*BUFF_SIZE);
  getcwd(shellDir, BUFF_SIZE-1);
  curDir = malloc(sizeof(char)*BUFF_SIZE);
  curDir[0] = '~';
  printf("\n\n");
}

int main()
{
  char * user;
  char * host;
  initialize_shell(&user, &host);

  char * line;
  char ** args;
  char ** commands;
  int status=1;
  int background;

  while(status)
  {
    //bg_proc_list = check_bg_proc(bg_proc_list);

    printf("[%s@%s : %s] > ",user,host,curDir);
    fflush(stdin);
    line = getline_my();

    commands = get_tokens(line, COMMAND_DELIM, TOKEN_BUFF_SIZE);

    if(commands)
    {
      for(int i = 0; status && commands[i]; i++)
      {
        args = get_tokens(commands[i], TOKEN_DELIM, TOKEN_BUFF_SIZE);
        background = checkForBackground(args);
        status = execute_line(args, background);
        free(args);
      }
    }

    free(line);
    free(commands);
  }

  return 0;
}
