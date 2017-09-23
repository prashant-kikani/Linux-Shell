#include "execute.h"

void handler(int sig, siginfo_t *siginfo, void *context)
{
  int status;
  pid_t pid;
  pid = waitpid(-1, &status, WNOHANG);
  if(pid>0)
    printf("pid %d exited with status %d\n", pid, WEXITSTATUS(status));
}

int execute_system_command(char ** args, int background)
{
  pid_t pid;
  pid = fork();
  if(background)
  {
    struct sigaction act;
    act.sa_sigaction=&handler;
    sigaction(SIGCHLD,&act,NULL);
  }
  if(pid<0)
    perror("Error ");
  else if(pid==0)
  {
    if(execvp(args[0], args) == -1)
      perror("Error ");
    exit(EXIT_FAILURE);
  }
  else if(!background)
  {
    int status, wpid;
    do
    {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while(!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}

int execute_line(char ** args, int background)
{
  if(args==NULL)
    return 1;

  for(int i=0; shell_command_str[i]; i++)
  {

    if(strcmp(shell_command_str[i],args[0])==0)
      return (*shell_command[i])(args);
  }
  execute_system_command(args, background);
  return 1;
}
