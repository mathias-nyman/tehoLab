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

typedef struct R
{
	State state;
	void (*transition)(struct R *regexp, const char c);
	Boolean (*is_final)(struct R *regexp, Boolean is_last);
	struct R *next;
} Regexp;

void short_transition(Regexp *regexp, const char c)
{
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
}

void longer_transition(Regexp *regexp, const char c)
{
	switch(regexp->state)
	{
		case INITIAL:
			if(isalnum(c) || c == '_')
				regexp->state = ALNUM;
			break;
		case ALNUM:
			if(isdigit(c))
				regexp->state = DIGIT;
			else if(!isalnum(c) && c != '_')
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
}

Boolean short_is_final(Regexp *regexp, Boolean is_last)
{
	return regexp->state == FINAL || (is_last && regexp->state == DIGIT);
}

Boolean longer_is_final(Regexp *regexp, Boolean is_last)
{
	return regexp->state == FINAL;
}

Boolean find_regex(const char *line, Boolean or_operator)
{
	if(strlen(line) > 0)
	{
		Regexp shortR = {INITIAL, short_transition, short_is_final, 0}, longerR;
		Regexp *head = &shortR;
		
		if(or_operator)
		{
			Regexp tmp = {INITIAL, longer_transition, longer_is_final, 0};
			longerR = tmp;
			head->next = &longerR;
		}
		int i = 0;
		do {
			Regexp *curr;
			for(curr = head; curr != 0; curr = curr->next)
			{
				curr->transition(curr, line[i]);
				if(curr->is_final(curr, line[i+1] == '\0'))
					return TRUE;
			}
			i++;
		} while(line[i] != '\0');
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
