#include"main.h"

void extract_external_commands(char **external_commands)
{
	int fd,i,j;
	char buffer[25] = {'\0'};
	char ch;

	fd = open("external_commands.txt",O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	
	i = 0;
	j = 0;

	while(read(fd,&ch,1) >0)
	{
	
		if(ch != '\n')
		{
	          buffer[i++]= ch;
		}
		else
		{
		  external_commands[j] = calloc(strlen(buffer)+1,sizeof(char));
		  strcpy(external_commands[j++],buffer);

		  external_commands[j] = '\0';

		  memset(buffer,'\0',25);

		  i = 0 ;
		}
	}
}
