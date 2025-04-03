#include"main.h"

int check_command_type(char *command)

{
	//LIST OF BUILT IN COMMANDS
	char *builtins[] = {"echo", "printf", "read", "cd", "pwd", "pushd", "popd", "dirs", "let","eval",
		            "set","unset", "export", "declare", "typeset", "readonly", "getopts", "source",
			    "exit", "exec", "shopt", "caller", "true", "type", "hash", "bind", "help", NULL};
	
	//CHECK IF THE USER PRESSES ENTER KEY
	if(strcmp(command,"\0") == 0)
	{	
		return NO_COMMAND; //MACRO(NO_COMMAND)
	}


	//CHECK IF THE COMMAND IS BUILTIN COMMAND
	for(int i = 0 ; builtins[i]!= NULL ; i++)
	{
		if(strcmp(command,builtins[i]) == 0)
		{
			return BUILTIN;
		}
	
	}


	//TO EXTRACT THE EXTERNAL COMMAND
	char *external_commands[155]= {NULL};
	extract_external_commands(external_commands);
	
	
	//CHECK IF THE COMMAND IS EXTERNAL COMMAND
	for(int i = 0 ; external_commands[i]!= NULL ; i++)
	{
                if(strcmp(command,external_commands[i]) == 0)
                {
                        return EXTERNAL;
                }
 
        }



}
