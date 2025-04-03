#include"main.h"

void execute_internal_commands(char *input_string)
{
	//EXIT: TO EXIT THE PROGRAM
	char *path,*backup_path;
	if(strncmp("exit",input_string,4) == 0)
	{
		exit(1);
	}

	//PWS: TO PRINT THE PRESENT WORKING DIRECTORY
	if(strncmp("pwd",input_string,3) == 0)
        {
                system("pwd");
        }
	
	//CD: TO CHANGE THE DIRECTORY
	if(strncmp("cd",input_string,2) == 0)
        {
	       
              //INPUT_STRING[] = CD ABC
	      path = strtok(input_string, " ");
	      while(path != NULL)
	      {
		      backup_path= path;
		      path = strtok(NULL, " ");
	      }

	      chdir(backup_path);
        }


}
