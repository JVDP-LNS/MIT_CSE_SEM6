#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
	if(argc <= 2) {
		printf("ERROR - Insufficient arguements passed to program\n");
		return 0;
	}
	FILE *fp1, *fp2;
	char c = '\0';
	int curPos = 0;

	fp1 = fopen(argv[1], "r+");
	if(fp1 == NULL) {
		printf("ERROR - supplied file %s doesnt exist\n", argv[1]);
	}
	fp2 = fopen(argv[2], "w+");

	fseek(fp1, 1, SEEK_END);	//go past EOF to avoid overflow in case of empty file
	curPos = ftell(fp1);		//use separate var to track current position to handle overflow once operation finishes
	printf("File size: %d bytes\n", curPos - 1);
	if(curPos == 1) {
		fclose(fp1);
		fclose(fp2);
		return 0;
	}
	while(curPos >= 2) {
		fseek(fp1, -2, SEEK_CUR);	//since we start 2 pos after last char, if non-empty file
		c = fgetc(fp1);
		fputc(c, fp2);			//increments current pos by 1, hence we decrement by 2 above
		curPos--;
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}  