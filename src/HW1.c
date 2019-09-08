#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"
#include "RKMName.h"

int main(int argc, char* argv[])
{
	printf("Hello, World! \n");
	srand(time(NULL));
	if(tests()) {
		production(argc, argv);
	}
	else {
		puts("Tests have failed.");
	}
	return EXIT_SUCCESS;
}
