#include "main.h"

pid_t pid;
void scan_input(char *prompt, char *input_string)
{
	char *command;
	int command_type,status,ret_status;
	

	//REGISTER THE SIGNAL
	signal(SIGINT,signal_handler);
	while(1)
	{
	
	//DISPLAY THE PROMPT
        printf(ANSI_COLOR_RED "[%s]$" ANSI_COLOR_RESET,prompt);
	
	//CLEAR THE OUTPUT BUFFER
	fflush(stdout);
	
	//SCAN THE INPUT TILL THE END OF THE LINE
	scanf("%[^\n]s",input_string);

	//CLEAR THE INPUT BUFFER
	getchar();


	//CUSTOMIZE THE PROMPT
	if( !(strncmp("PS1=",input_string,4)))

	{
		if(input_string[4] != ' ')
	{
		strcpy(prompt,&input_string[4]);


		//FLUSH THE INPUT STRING
		memset(input_string,'\0',25);
		continue;
	}

	}
	

	//TO GET THE COMMAND
	command = get_command(input_string);

	// CHECK WHETHER THE COMMAND IS INTERNAL OR EXTERNAL
	command_type = check_command_type(command);
	//printf("The command type is %d\n",command_type);


	//IF THE COMMAND IS EXTERNAL	
	if(command_type == EXTERNAL)      // ls, ls -l, ls | wc
	{

	//CREATE A CHILD PROCESS
	pid = fork();
	if(pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if(pid == 0)
	{

		//CHILD EXECUTES THE COMMAND
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

		//PARENT EXECUTES
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
	

	//CLEAR THE INPUT FOR NEXT ITTERATION
	memset(input_string,'\0' ,25);
        }
       

	//CALL THE FUNCTION TO IMPLEMENT ECHO COMMANDS
	echo(input_string,status);
	

	//INTERNAL COMMANDS	
	execute_internal_commands(input_string);
        

	//NOT A VALID COMMAND
	if((command_type != NO_COMMAND) && (command_type != BUILTIN) && (command_type != EXTERNAL))
	{
		printf("%s : Command not found\n",input_string);
	}
	memset(input_string,'\0' ,25);
	}
		
}
