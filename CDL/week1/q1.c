#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
	if(argc <= 1) {
		printf("ERROR - Insufficient arguements passed to program\n");
		return 0;
	}
	FILE *fp1;
	char c = '\0';
	int charCount = 0;
	int lineCount = 0;

	fp1 = fopen(argv[1], "r+");
	if(fp1 == NULL) {
		printf("ERROR - supplied file %s doesnt exist\n", argv[1]);
	}
	c = fgetc(fp1);
	while(c != EOF) {
		charCount += (c != '\n' && c != '\t');	//dont count new line and tab spaces 
		if(c == '\n')
			lineCount++;
		c = fgetc(fp1);
	}
	lineCount += charCount > 0; //if empty file then 0 lines, else add 1 to account for lack of a new line symbol before 1st line
	printf("Line Count = %d\nChar Count = %d\n", lineCount, charCount);
	return 0;
}