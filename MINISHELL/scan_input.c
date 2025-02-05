#include "main.h"

pid_t pid;
void scan_input(char *prompt, char *input_string)
{
	char *command;
	int command_type,status,ret_status;

	signal(SIGINT,signal_handler);
	while(1)
	{

        printf(ANSI_COLOR_RED "[%s]$" ANSI_COLOR_RESET,prompt);

	fflush(stdout);
	
	scanf("%[^\n]s",input_string);

	getchar();

	if( !(strncmp("PS1=",input_string,4)))

	{
		if(input_string[4] != ' ')
	{
		strcpy(prompt,&input_string[4]);
		memset(input_string,'\0',25);
		continue;
	}

	}

	command = get_command(input_string);
	command_type = check_command_type(command);
	//printf("The command type is %d\n",command_type);
 	
	if(command_type == EXTERNAL)
	{
	pid = fork();
	if(pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if(pid == 0)
	{
		ret_status = system(input_string);
		if(ret_status == 0)
		{
			exit(0);
		}
		else
		{
			exit(1);
		}
	}
	else
	{
		wait(&status);
                if(WIFEXITED(status))
		{
			printf("Chil wih PID: %d terminated normally\n", pid);
		}
		else if(WIFSIGNALED(status))
		{
			printf("Child with pid : %d terminated by a signal\n",pid);
			printf("Sig# : %d\n",WTERMSIG(status));
		}
	}

	memset(input_string,'\0' ,25);
        }
       
	echo(input_string,status);
	
	execute_internal_commands(input_string);
        //printf("command_type = %d\n",command_type);
	if((command_type != NO_COMMAND) && (command_type != BUILTIN) && (command_type != EXTERNAL))
	{
		printf("%s : Command not found\n",input_string);
	}
	memset(input_string,'\0' ,25);
	}
		
}
