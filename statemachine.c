#include<stdio.h>

typedef enum
{
	downstate,
	startingstate,
	runningstate,
	exitingstate,
}states;

typedef enum
{
	downevent,
	startingevent,
	runningevent,
	exitingevent,
}events;

int opt=1;
int starting();
void running();
void exiting();
states nextstate;
states nextstate=downstate;

int main()
{
	//states nextstate=downstate;
	events newevent;
	printf("\n\t process starts \t\n");
	do
	{
		switch(nextstate)
		{
			case downstate:
				{
					int select;
					printf("\npresent state is downstate\n"
					       "\nenter 0 for present state and 1 for next state\n");
					scanf("%d",&select);
					if(select == 1)
					{
						//nextstate=starting state();
						starting();
					//	printf("next state is starting state");
					}
					else
					{
						printf("\nstate not changed\n");
					}
				}
				break;
		}
	}while(opt == 0);
}
				
void running()
{
	int select;
	printf("\n\t present state is running state \n");
	printf("\n enter 1 for same state and 0 for exiting state\n");
	scanf("%d",&select);
	if (select == 1)
	{
		printf("\nprocess present in running state\n");
	}
	else
	{
		exiting();
	}
}


void exiting()
{
	printf("\npresent state is exiting state\n");
	printf("\nenter 0 for down state\n");
	int select;
	scanf("%d",&select);
	opt =0;
}

		

int starting()
{
	int select;
	printf("\n  present state is starting state  \n");
	printf("\nenter 0 for exiting state and 1 for runningstate\n");
	scanf("%d",&select);
	if(select == 1)
	{
		running();
	}
	else
	{
		exiting();
	}
}



