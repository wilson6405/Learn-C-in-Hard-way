#include <stdio.h>

int
main(int argc, char *argv[])
{
	int i = 0;

	if(argc == 1) {
		printf("Please enter arguments.\n");
	} else if(argc > 1 && argc < 4) {
		printf("Here's your argument:\n");

		for (i = 1; i < argc; i++)
		{
			printf("%s ", argv[i]);
		}
		printf("\n");
	} else if(argc == 4){
		printf("Perfect!\n");
	} else {
		printf("You have too many arguments. You suck.\n");
	}

	return 0;
}