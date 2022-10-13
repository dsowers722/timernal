#include <stdio.h>
#include <stdlib.h>

char *time;
char *characters[10];

int main(int argc, char* argv[]) {
	time = argv[1];
	FILE *file = fopen("./numbers.txt", "r");
	// TODO fix the file reading issues.
	fscanf(file, "  %c", characters[0]);
	printf("%s", characters[0]);
	return 1;
}
