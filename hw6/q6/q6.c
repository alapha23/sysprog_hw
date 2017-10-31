#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

pid_t pid;

void sig_handler(int num){
	printf("Child died\n");
	exit(0);
}

int main(int argc, char * argv[], char * envp[])
{
	struct sigaction action;
	memset(&action, '\0', sizeof(action));
	action.sa_handler = sig_handler;
	if(sigaction(SIGUSR1, &action, NULL)<0)
		perror("Error receiving signal\n");

	if((pid = fork()) < 0)
		perror("Error forking\n");
	if(pid == 0)
	{
	  printf("Child start executing command\n");

	  if(argc < 2)
	    printf("Usage: ./q6 <command> <option>. No command found\n");
	  if(argc < 3)
	    printf("Usage: ./q6 <command> <option>. No option found\n");

	  char a[40];
	  strcpy(a, "/bin/");
	  strcat(a, argv[1]);
	  printf("Command is %s \n", a);
	  char * const b[] = {argv[1], argv[2], NULL};
	  printf("option is %s\n\n", b[0]);
	  int check = 0;
	  if(((check = execve(a, b, envp) )!= 0))
	    perror("Error execve\n");

	}
	
	if(waitpid(pid, NULL, 0)>0)
		printf("Parent came back to execution\n");
	exit(0);
}
