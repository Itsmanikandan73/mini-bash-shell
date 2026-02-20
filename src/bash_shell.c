#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

int main(){

	char buffer[1024];
	int bytes_read;

	while(1){
		
		write(1,"Solo_shell@runlevel3~: ",24);
		bytes_read = read(0, buffer, sizeof(buffer));
		if (bytes_read <= 0) break;

		//1. clean the newline
		if (buffer[bytes_read - 1] == '\n') buffer[bytes_read - 1] = '\0';

		//2. THE CHOPPER (Now happens in the parent)
		char *args[10];
		args[0] = strtok(buffer," "); //Get the first word

		int i = 0;
		
		while(args[i] != NULL){
			i++;
			args[i] = strtok(NULL, " "); //Get the next word
		}

		//3. THE "CD" CHECK (The build-in)
		//strcmp return 0 if strings are identical
		if (strcmp(args[0], "cd") == 0){
			// Check the user provided the path args[0]
			if (args[1] != NULL){
				// chdir is the system call to change folder 
				if (chdir(args[1]) != 0){
					perror("cd failed");
				}
			}
			continue; //skip the fork! go back to start loop.
		}
		//4.THE FORK (for everything else like ls, date, whoami)
		if(fork() == 0){
			//child just runs the args we already chopped
			execvp(args[0], args);
			perror("Excution failed");
			exit(1);
		}
		else{
			wait(NULL);
		}
		
	}
	return 0;
}
