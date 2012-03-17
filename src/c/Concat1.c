/*
 *  Concat1.c
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

void concatenate(const char *input_file, int dry_run)
{
	FILE *f = fopen(input_file, "r");
	
	if(f == 0)
	{
		fprintf(stderr, "Could not open file %s\n", input_file);
		exit(1);
	}
	
	char tmp[MAX_WORD_LENGTH];

	if(dry_run)
		while(EOF != fscanf(f, "%s", tmp));
	else
	{
		char result[MAX_LINE_LENGTH];
		while(EOF != fscanf(f, "%s", tmp))
		{
			strcat(result, tmp);
		}
	}
	
	fclose(f);
}

int main(int argc, char **argv)
{
	int dry_run = 0;
	
	switch(argc)
	{
		case 2:
			break;
		case 3:
			if(!strcmp(argv[2], "--dry-run"))
				dry_run = 1;
			else
			{
				fprintf(stderr, "Illegal argument: %s\n", argv[2]);
				exit(1);
			}
			break;
		default:
			fprintf(stderr, "Illegal number of arguments\n");
			exit(1);
	}
	
	concatenate(argv[1], dry_run);
	
    return 0;
}
