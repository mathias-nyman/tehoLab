/*
 *  Regexp1.c
 *  
 *
 *  Created by Jukka Aro on 10.3.2012.
 *
 */
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 150

void regex_match(const char *input_file, int or_operator)
{
	FILE *f = fopen(input_file, "r");
	
	if(f == 0)
	{
		fprintf(stderr, "Could not open file %s\n", input_file);
		exit(1);
	}
	
	regex_t preg_normal, preg_or;
	const char *normal_pattern = "[[:digit:]+]";
	const char *or_pattern = "[[[:alnum:]_]+][[:digit:]+]\\.";

	if(0 != regcomp(&preg_normal, normal_pattern, REG_NOSUB) ||
	   0 != regcomp(&preg_or, or_pattern, REG_NOSUB))
	{
		fprintf(stderr, "regcomp() failed\n");
		fclose(f);
		exit(EXIT_FAILURE);
	}

	int matches = 0;
	char line[MAX_LINE_LENGTH];

	clock_t total = 0;
	
	if(or_operator)
	{
		while(fgets(line, MAX_LINE_LENGTH, f))
		{
			clock_t start = clock();
			
			if(0 == regexec(&preg_normal, line, 0, 0, 0) ||
			   0 == regexec(&preg_or, line, 0, 0, 0))
			{
				matches++;
			}
			clock_t end = clock();
			total += end-start;
		}
	}
	else
	{
		while(fgets(line, MAX_LINE_LENGTH, f))
		{
			clock_t start = clock();
			
			if(0 == regexec(&preg_normal, line, 0, 0, 0))
			{
				matches++;
			}
			clock_t end = clock();
			total += end-start;
		}
	}

	regfree(&preg_normal);
	regfree(&preg_or);
	fclose(f);
	printf("%.4lf\n", (double)total/CLOCKS_PER_SEC);
}

int main(int argc, char **argv)
{
	if(argc < 2 || argc > 3)
	{
		fprintf(stderr, "Illegal number of arguments\n");
		exit(1);
	}
	
	int or_operator = 0;
	
	if(argc == 3)
	{
		if(!strcmp(argv[2], "--with-or-operator"))
			or_operator = 1;
		else
		{
			fprintf(stderr, "Illegal argument: %s\n", argv[2]);
			exit(1);
		}
	}
	
	regex_match(argv[1], or_operator);
    return 0;
}
