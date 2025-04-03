#include"main.h"

void echo (char *input_string, int status)
{
	//ECHO $?, TO GET THE EXIT STATUS OF THE LAST COMMAND
	if(strncmp("echo $?",input_string,7)== 0)
	{
		printf("%d\n",status);
	}

	//ECHO $$, PID OF THE MINISHELL
	if(strncmp("echo $$",input_string,7)== 0)
        {
                printf("%d\n",getpid());
        }

	//ECHO $SHELL, TO PRINT THE EXECUTABLE PATH OF THE SHELL
	if(strncmp("echo $SHELL",input_string,11)== 0)
        {
                system("pwd"); //PRINT THE PRESENT WORKING DIRECTORY
        }

}
