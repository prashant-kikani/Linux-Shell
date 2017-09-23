#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/utsname.h>

#define TOKEN_DELIM " \t\n\r\a"
#define COMMAND_DELIM ";"

void initialize_shell(char ** user, char ** host);
char * getline_my();
char ** get_tokens(char *, char * _TOKEN_DELIM, int _TOKEN_BUFF_SIZE);
int checkForBackground(char ** args);
int execute_line(char ** args, int background);

int TOKEN_BUFF_SIZE = 64;
int BUFF_SIZE = 1024;
char * curDir;
char * shellDir;

char *shell_command_str[] = {
  "cd",
  "help",
  "exit",
  "echo",
  "pwd",
  "pinfo",
  NULL
};
int cd_my(char ** args);
int help_my(char ** args);
int echo_my(char ** args);
int exit_my(char ** args);
int pwd_my(char ** args);
int pinfo_my(char ** args);


int (*shell_command[])(char**) = {
  &cd_my,
  &help_my,
  &exit_my,
  &echo_my,
  &pwd_my,
  &pinfo_my
};



int main();
