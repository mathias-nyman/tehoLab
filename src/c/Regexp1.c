/*
 *  Regexp1.c
 *  
 *
 *  Created by Jukka Aro on 15.3.2012.
 *
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 250

typedef enum
{
	FALSE = 0,
	TRUE = 1
} Boolean;

typedef enum
{
	INITIAL,
	ALNUM,
	DIGIT,
	FINAL
} State;

typedef enum
{
	SINGLE,
	OR_OPERATOR
} Type;

typedef struct
{
	Type type;
	State state;
} Regexp;

void transition(Regexp *regexp, const char c)
{
	switch(regexp->type)
	{
	case SINGLE:
		switch(regexp->state)
		{
		case INITIAL:
			if(isdigit(c))
				regexp->state = DIGIT;
			break;
		case DIGIT:
			if(!isdigit(c))
				regexp->state = FINAL;
			break;
		default:
			break;
		}
		break;
	case OR_OPERATOR:
		switch(regexp->state)
		{
			case INITIAL:
				if(isalnum(c))
					regexp->state = ALNUM;
				break;
			case ALNUM:
				if(isdigit(c))
					regexp->state = DIGIT;
				else if(!isalnum(c))
					regexp->state = INITIAL;
				break;
			case DIGIT:
				if(c == '.')
					regexp->state = FINAL;
				else if(!isdigit(c))
					regexp->state = INITIAL;
				break;
			default:
				break;
		}
		break;
	default:
		break;
	}
}

Boolean find_regex(const char *line, Boolean or_operator)
{
	if(strlen(line) > 0)
	{
		if(or_operator)
		{
			Regexp regexp1 = {0}, regexp2 = {0};
			regexp1.type = SINGLE;
			regexp2.type = OR_OPERATOR;
			regexp1.state = regexp2.state = INITIAL;
			int i = 0;
			do {
				transition(&regexp1, line[i]);
				transition(&regexp2, line[i]);
				i++;
				if(regexp1.state == FINAL ||
				   regexp2.state == FINAL ||
				   (line[i] == '\0' && regexp1.state == DIGIT))
					return TRUE;
			} while(line[i] != '\0');
		}
		else
		{
			Regexp regexp = {0};
			regexp.type = SINGLE;
			regexp.state = INITIAL;
			int i = 0;
			do {
				transition(&regexp, line[i]);
				i++;
				if(regexp.state == FINAL ||
				   (line[i] == '\0' && regexp.state == DIGIT))
					return TRUE;
			} while(line[i] != '\0');
		}
	}
	return FALSE;
}

void regex_match(const char *input_file, const Boolean or_operator)
{
	FILE *f = fopen(input_file, "r");
	
	if(f == 0)
	{
		fprintf(stderr, "Could not open file %s\n", input_file);
		exit(1);
	}

	int matches = 0;
	char line[MAX_LINE_LENGTH];
	
	while(fgets(line, MAX_LINE_LENGTH, f))
	{
		if(find_regex(line, or_operator))
			matches++;
	}
	fclose(f);
}

int main(int argc, char **argv)
{
	if(argc < 2 || argc > 3)
	{
		fprintf(stderr, "Illegal number of arguments\n");
		exit(1);
	}
	
	Boolean or_operator = FALSE;
	
	if(argc == 3)
	{
		if(!strcmp(argv[2], "--with-or-operator"))
			or_operator = TRUE;
		else
		{
			fprintf(stderr, "Illegal argument: %s\n", argv[2]);
			exit(1);
		}
	}
	
	regex_match(argv[1], or_operator);
    return 0;
}
