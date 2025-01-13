#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
	if(argc <= 3) {
		printf("ERROR - Insufficient arguements passed to program\n");
		return 0;
	}
	FILE *fp1, *fp2, *fp3;
	char c1 = 'a';
	char c2 = 'a';
	int done1 = 0;
	int done2 = 0;

	fp1 = fopen(argv[1], "r+");
	if(fp1 == NULL) {
		printf("ERROR - supplied file %s doesnt exist\n", argv[1]);
	}
	fp2 = fopen(argv[2], "r+");
	if(fp1 == NULL) {
		printf("ERROR - supplied file %s doesnt exist\n", argv[2]);
	}
	fp3 = fopen(argv[3], "w+");

	while(c1 != EOF || c2 != EOF) {
		if(c1 != EOF)
			c1 = fgetc(fp1);
		if(c2 != EOF)
			c2 = fgetc(fp2);
		while(c1 != EOF && c1 != '\n') {
			fputc(c1, fp3);
			c1 = fgetc(fp1);
		}
		fputc('\n', fp3);
		while(c2 != EOF && c2 != '\n') {
			fputc(c2, fp3);
			c2 = fgetc(fp2);
		}
		fputc('\n', fp3);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	return 0;
}