#include "stdio.h"
int main(void) {
	char* first = "H";	//could change "H" to something like gameboard.row[blah][blah]
	//		first = ####first####
	char* sec = "e";
	char* third = "l";
	char* fourth = "l";
	char* fifth = "o";
	printf("//////////\\\\\\\\\\\\\\\\\\\\\\\n");
	for (int i = 0; i < 6; i++)
	{

		printf("|   |   |   |   |   |\n");
		printf("| %s | %s | %s | %s | %s |\n", first, sec, third, fourth, fifth);
		printf("|   |   |   |   |   |\n");
		if (i < 2)
		{
			printf("//////////\\\\\\\\\\\\\\\\\\\\\\\n");
		}if (i == 2)
		{
			printf("|||||||||||||||||||||\n");
		}
		if (i > 2)
		{
			printf("\\\\\\\\\\\\\\\\\\\\\\\//////////\n");
		}
	}

	return 0;
}