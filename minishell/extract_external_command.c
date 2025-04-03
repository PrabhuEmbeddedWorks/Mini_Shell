#include"main.h"

void extract_external_commands(char **external_commands)
{

	//VARIABLE DECLARATION
	int fd,i,j;
	char buffer[25] = {'\0'};
	char ch;


	//OPEN THE FILE IN READ MODE
	fd = open("external_commands.txt",O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	
	i = 0;
	j = 0;


	//READ THE COMMAND ONE BY ONE
	while(read(fd,&ch,1) >0)
	{
	
		if(ch != '\n')
		{
	          buffer[i++]= ch; //BASH
		}
		else
		{

		  //ALLOCATE SUFFICIENT MEMORY
		  external_commands[j] = calloc(strlen(buffer)+1,sizeof(char));
		  
		  //COPY THE CONTENTS
		  strcpy(external_commands[j++],buffer);
		 
		  //APPEND THE NULL CHARACTER AT THE END
		  external_commands[j] = '\0';

		  //CLEAR THE BUFFER
		  memset(buffer,'\0',25);

		  //RE-INITIALIZE
		  i = 0 ;
		}
	}
}
