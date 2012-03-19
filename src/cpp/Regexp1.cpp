/*
 *  Regexp1.cpp
 *  
 *
 *  Created by Jukka Aro on 15.3.2012.
 *
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>

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

class Regexp
{
public:
	virtual void transition(char c) = 0;
	virtual bool isFinal(bool isLast) = 0;
};

class ShortRegexp : public Regexp
{
public:
	ShortRegexp() : state(INITIAL) {}
	
	void transition(const char c)
	{
		switch(state)
		{
			case INITIAL:
				if(isdigit(c))
					state = DIGIT;
				break;
			case DIGIT:
				if(!isdigit(c))
					state = FINAL;
				break;
			default:
				break;
		}
	}
	
	bool isFinal(bool isLast) { return state == FINAL || (isLast && state == DIGIT); }

private:
	Type type;
	State state;
};

class LongerRegexp : public Regexp
{
public:
	LongerRegexp() : state(INITIAL) {}

	void transition(const char c)
	{
		switch(state)
		{
			case INITIAL:
				if(isalnum(c) || c == '_')
					state = ALNUM;
				break;
			case ALNUM:
				if(isdigit(c))
					state = DIGIT;
				else if(!isalnum(c) && c != '_')
					state = INITIAL;
				break;
			case DIGIT:
				if(c == '.')
					state = FINAL;
				else if(isalnum(c) || c == '_')
					state = ALNUM;
				else if(!isdigit(c))
					state = INITIAL;
				break;
			default:
				break;
		}
	}
	bool isFinal(bool isLast) { return state == FINAL; }

private:
	Type type;
	State state;
};
	
bool find_regex(std::string &line, bool or_operator)
{
	if(line.length() > 0)
	{
		std::vector<Regexp*> regexps;
		ShortRegexp shortR = ShortRegexp();
		regexps.push_back(&shortR);
		LongerRegexp longerR = LongerRegexp();
		if(or_operator)
		{
			regexps.push_back(&longerR);
		}
		int i = 0;
		do {
			for(std::vector<Regexp*>::iterator it = regexps.begin(); it != regexps.end(); it++)
			{
				(*it)->transition(line[i]);
				if((*it)->isFinal(i+1 == line.length()))
				   return true;
			}
			i++;
		} while(i < line.length());
	}
	return false;
}

void regex_match(const char *input_file, bool or_operator)
{
	std::ifstream ifs(input_file, std::ifstream::in);
	std::string line;
	int matches = 0;

	while(getline(ifs, line))
	{
		if(find_regex(line, or_operator))
			matches++;
	}
	ifs.close();
}

int main(int argc, char **argv)
{
	bool or_operator = false;
	bool dry_run = false;

	switch(argc)
	{		
		case 2:
			break;
		case 3:
			if(!strcmp(argv[2], "--with-or-operator"))
			{
				or_operator = true;
			}
			else if(!strcmp(argv[2], "--dry-run"))
			{
				dry_run = true;
			}
			else
			{
				fprintf(stderr, "Illegal argument: %s\n", argv[2]);
				exit(1);
			}
			break;
		case 4:
			if(!strcmp(argv[2], "--with-or-operator"))
			{
				or_operator = true;
			}
			else
			{
				fprintf(stderr, "Illegal argument: %s\n", argv[2]);
				exit(1);
			}

			if(!strcmp(argv[3], "--dry-run"))
			{
				dry_run = true;
			}
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
	if(!dry_run)
		regex_match(argv[1], or_operator);
	
    return 0;
}
