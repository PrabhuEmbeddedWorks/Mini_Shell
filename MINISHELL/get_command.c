#include"main.h"

char *get_command(char *input_string)
{
	static char command[25] ={'\0'};
	int i = 0;
	while(1)
	{
	  if(*input_string == ' ' || *input_string == '\0')
	  {
		  break;
	  }
	  command[i++]= (*input_string);
	  input_string++;
	}
	command[i] = '\0';
	return command;
}
