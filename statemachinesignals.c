#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void starting();
void running();
void exiting();

int time;
int pid;
 
void main()
{
	pid=fork();
	if (pid== 0)
	{
		signal(SIGUSR1, starting);
		signal(SIGUSR2, running);
		signal(SIGQUIT, exiting);
		for( ; ;)
			;
	}
	else
	{
		printf("\n\tprocess starts");
		printf("\npresent state is down state");
		printf("\n sending signal for starting state\n");
		kill(pid, SIGUSR1);
		sleep(5);
		printf("\nsending signal for running state \n\n");
		printf("\nenter time to be in running state\n");
		scanf("%d",&time);
		kill(pid, SIGUSR2);
		sleep(time);
		printf("\nsending signal for exiting\n\n");
		kill(pid, SIGQUIT);
		sleep(5);
	}
}
 
void starting()
{
	signal(SIGUSR1, starting);
    	printf("%d",pid);
    	printf("\nI have receive signal \n"
			"\npresent state is starting state\n");
}
 
void running()
{
	signal(SIGUSR2, running);
 	printf("\n I have received a signal\n"
           		 "present state is running state\n");
}
 
void exiting()
{
	printf("\nprocess is in exiting state\n");
	printf("\nprocess completed\n");
	exit(0);
}
	
	
	

