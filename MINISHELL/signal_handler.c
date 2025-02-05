#include"main.h"

extern pid_t pid;
void signal_handler(int sig_num)
{
	if (pid !=0)
	{
		if(sig_num == SIGINT)
		{
			kill(pid, SIGKILL);
		}
	}
}





