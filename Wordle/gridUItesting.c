#include "stdio.h"
void graph() {
	char* first = "H";
	char* sec = "e";
	char* third = "l";
	char* fourth = "l";
	char* fifth = "o";
	for (int i = 0; i < 5; i++)
	{
		printf("//////////\\\\\\\\\\\\\\\\\\\\\\\n");
		printf("|   |   |   |   |   |\n");
		printf("| %s | %s | %s | %s | %s |\n", first, sec, third, fourth, fifth);
		printf("|   |   |   |   |   |\n");
	}
	printf("\\\\\\\\\\\\\\\\\\\\\\\//////////\n");
}