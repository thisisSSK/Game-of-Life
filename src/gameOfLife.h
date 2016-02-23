#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int check_input_count(int);
int parse_param(char* );

int check_input_count(int argc) {

	char *ptr;
	if (argc != 4) {
		printf("Please follow the format: gameOfLife <width> <height> <# cells>\n");
		exit(1);
	}
	return 0;
}

int parse_param(char* argv) {
	char* ptr;
	int param = strtol(argv, &ptr, 10);
	if (strcmp(ptr,argv) == 0) {
		printf("X should be a number!\n");
		exit(1);
	}
	return param;
}
