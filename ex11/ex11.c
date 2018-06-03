#include <stdio.h>

int
main(int argc, char *argv[])
{
	int i = 0;
	while(argc){
		printf("arg %d: %s\n", i, argv[i]);
		i++;
		if(i >= argc) break;
	}

	char *states[] = {
		"California", "Oregon",
		"Washington", "texas"
	};

	int num_states = 4;
	i = 0;

	int count = 0;
	if (num_states > argc) 
		count = argc;
	else
		count = num_states;

	while(i < count) {
		states[i] = argv[i];
		printf("state %d: %s\n", i, states[i]);
		i++;
	}

	printf("%p\n", states[1]);
	printf("%d\n", *states[1]);
	printf("%p\n", argv[0]);
	return 0;
}