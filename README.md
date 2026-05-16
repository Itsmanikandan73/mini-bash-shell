# simple Bash Shell

A simple, functional **Bourne Again SHell (Bash)** clone written in pure C from scratch.

This project is a minimal command-line interpreter that demonstrates how shells work under the hood using system calls like `fork()`, `execvp()`, and `chdir()`.

---

## Features

- Interactive command prompt
- Built-in `cd` command (changes directory)
- Execution of external commands and programs
- Basic command parsing using tokenization
- Supports common commands like `ls`, `pwd`, `whoami`, `date`, `cat`, etc.

### Not yet implemented
- Pipes (`|`)
- I/O Redirection (`>`, `<`, `>>`)
- Environment variables
- Quoting and escaping
- Job control / signals
- History and tab completion

---

## Build & Run

```bash
# Clone the repository
git clone https://github.com/Itsmanikandan73/Bash-shell.git
cd Bash-shell

# Compile
gcc src/shell.c -o shell -Wall -Wextra

# Run
./shell

A simple, functional **Bourne Again SHell (Bash)** clone written in pure C from scratch.

This project is a minimal command-line interpreter that demonstrates how shells work under the hood using system calls like `fork()`, `execvp()`, and `chdir()`.

---

## Features

- Interactive command prompt
- Built-in `cd` command (changes directory)
- Execution of external commands and programs
- Basic command parsing using tokenization
- Supports common commands like `ls`, `pwd`, `whoami`, `date`, `cat`, etc.

### Not yet implemented
- Pipes (`|`)
- I/O Redirection (`>`, `<`, `>>`)
- Environment variables
- Quoting and escaping
- Job control / signals
- History and tab completion

---

## Build & Run

```bash
# Clone the repository
git clone https://github.com/Itsmanikandan73/Bash-shell.git
cd Bash-shell

# Compile
gcc src/bash_shell.c -o bash_shell -Wall -Wextra

# Run
./shell
```
# Example Usage
```
$ ./shell

bash-shell> ls
src  README.md  shell.c

bash-shell> pwd
/home/user/Bash-shell

bash-shell> cd src

bash-shell> whoami
itsmanikandan73

bash-shell> date
Sat May 16 07:45:12 UTC 2026

bash-shell> exit
```
# Project Structure
```
Bash-shell/
├── src/
│   └── shell.c     # Main source code
├── shell           # Compiled binary (after build)
└── README.md
```

