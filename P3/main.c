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
	}
}