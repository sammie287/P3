#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[])
{
	while(1){
		char command[4];
		int intValue;
		char stringValue[255];

		printf("Command? ");
		fflush(stdout);
		scanf("%s %d %s",command, &intValue, stringValue);

		if(!strcmp(command, "ina"))
			;//Run insert after method here
		else if(!strcmp(command, "inb"))
			;//Run insert before method here
		else if(!strcmp(command, "del"))
			;//Run delete method here
		else if(!strcmp(command, "rep"))
			;//Run replace method here
		else if(!strcmp(command, "prn"))
			;//Run print method here
		else if(!strcmp(command, "end"))
			;//Run end method here? Maybe just a break
	}
}