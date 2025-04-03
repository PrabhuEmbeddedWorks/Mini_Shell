#include "main.h"

int main()
{
	//TO CLEAR THE OUTPUR SCREEN
        system("clear");

	//DECLARE AN ARRAY TO STORE THE PROMPT
        char prompt[25] = "minishell";

	//TO SRORE INPUT STRING
        char input_string [25];
	
	//SCAN INPUT
        scan_input(prompt,input_string);
}
