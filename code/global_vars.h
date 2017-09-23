#ifndef GLOBAL_VARS
#define GLOBAL_VARS

extern const int BUFF_SIZE;
extern const int TOKEN_BUFF_SIZE;
extern char * curDir;
extern char * shellDir;

extern char *shell_command_str[]; /*= {
  "cd",
  "help",
  "exit",
  "echo",
  "pwd"
};*/

int cd_my(char ** args);
int help_my(char ** args);
int echo_my(char ** args);
int exit_my(char ** args);
int pwd_my(char ** args);
int pinfo_my(char ** args);

extern int (*shell_command[])(char**);/* = {
  &cd_my,
  &help_my,
  &exit_my,
  &echo_my,
  &pwd_my
};*/


#endif
