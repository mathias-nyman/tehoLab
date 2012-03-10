/*
 *  MatrixMult1.c
 *  
 *
 *  Created by Jukka Aro on 10.3.2012.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 3000
#define MAX_WORD_LENGTH 80

void concatenate(const char *input_file)
{
	FILE *f = fopen(input_file, "r");
	
	if(f == 0)
	{
		fprintf(stderr, "Could not open file %s\n", input_file);
		exit(1);
	}
	
	char result[MAX_LINE_LENGTH];
	char tmp[MAX_WORD_LENGTH];

	clock_t total = 0;

	while(EOF != fscanf(f, "%s", tmp))
	{
		clock_t start = clock();
		strcat(result, tmp);
		clock_t end = clock();
		total += end-start;
	}

	printf("%lf\n", ((double)total)/CLOCKS_PER_SEC);

	fclose(f);
}

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		fprintf(stderr, "Illegal number of arguments\n");
		exit(1);
	}
	
	concatenate(argv[1]);
	
    return 0;
}
