#include"main.h"

//EXTRACT THE COMMAND UNTILL THE SPACE IS ENCOUNTERED
char *get_command(char *input_string)
{
	//DECLARE AN ARRAY TO STORE THE COMMAND
	static char command[25] ={'\0'};
	int i = 0;

	//COLLECT THE COMMAND UNTIL SPACE OR NULL CHARACTER IS ENCOUNTERED
	while(1)
	{
	  if(*input_string == ' ' || *input_string == '\0')
	  {
		  break;
	  }
	  command[i++]= (*input_string);           //ECHO $?
	  input_string++;
	}
	command[i] = '\0'; // APPEND A NIULL CHARACTER '/0' AT THE END
	return command;
}
