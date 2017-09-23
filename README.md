# Shell
An interactive user defined shell in C

## Compile
- compile using simple make

## Run
- Run using './myshell'

## Features

### General Features
- Works almost like normal shell
- Keeps the directory where the shell is run, as home directory and shows the path of the current directory relative to that home directory
- Every command is run in new forked process

### Built-In Commands (Implemented)
These commands are implemented as a part of shell
- cd
- echo
- pwd
- pinfo
	- It returns process related information like pid, process status, memory, executable path, etc

### System Commands
- These commands are run as forked process which is served by system(OS)

### Background Processes
- Commands which have '&' appended, run in background
- When background process exits, shell display a message with its exit status
