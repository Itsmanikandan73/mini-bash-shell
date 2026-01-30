# mini-bash-shell

A simple functioning **Bernie shell** written in pure C from scratch.
It's a minimal command-line interpreter that can run basic commands, change directories, read files, and more - my first attempt to understand how real shell work using system calls.

## Features

- Interactive prompt
- Build-in: 'cd' (using 'chdir')
- Run external commands (via 'fork' + 'execvp')
- Basic command tokenizing with 'strtok'

Not implemented yet: pipes, redirection, environment variables, quotes, signals, etc..

## Installation & Usage

1. Clone the repository
```bash
https://github.com/Itsmanikandan73/mini-bash-shell.git
cd mini-bash-shell

#Compile & run
gcc bash_shell.c -o bash_shell -Wall
./bash_shell
```
## Example Usage
```bash
./bash_shell
$ls             //list directories and files
$cd             //chage directory
$pwd            //print the working directory
$whoami       //show the current user
$date         //show the current date
```
