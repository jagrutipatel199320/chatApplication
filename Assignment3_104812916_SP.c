
#include<stdio.h>

#include<stdlib.h>

#include<sys/types.h>

#include<string.h>

#define MAXLINE 100

#define MAX_OPTIONS 5


int main()

{

	char command[MAXLINE];

	char *command_arguments[MAX_OPTIONS];

	int pid,validity;

	int argumentc=0;		//initiating the command for argument count

	char *temp;			//declaring temp as token for command line



	while(1)

	{

		fgets(command,sizeof(command),stdin);

		temp = starttok(command,"\t\n");

		while(temp!=NULL)

		{

			command_arguments[argumentc]=temp;

			temp=starttok(NULL,"\t\n");

			argumentc++;

		}
	
		command_arguments[argumentc]='\0';

		if(strcmp(command_arguments[0],"exit")==0)

		{

			exit(0);

		}
			//now here we would fork the process

		pid=fork();		
//check if the process is being forked properly and then executing the command

		if(pid<0)

		{

			fprintf(stderr,"ERROR: in execution./n");

			return EXIT_FAILURE;

		}

		else if(pid == 0)

		{

			execvp(*command_arguments,command_arguments);

		}

		else

		{

			while(wait(&validity)==pid);	//delay or wait for the process to complete and end;

		}

	}

	return EXIT_SUCCESS;

}
