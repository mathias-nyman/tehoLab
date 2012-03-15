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
	Regexp(Type t) : type(t), state(INITIAL) {}

	State getState() { return state; }
	
	void transition(const char c)
	{
		switch(type)
		{
			case SINGLE:
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
				break;
			case OR_OPERATOR:
				switch(state)
			{
				case INITIAL:
					if(isalnum(c))
						state = ALNUM;
					break;
				case ALNUM:
					if(isdigit(c))
						state = DIGIT;
					else if(!isalnum(c))
						state = INITIAL;
					break;
				case DIGIT:
					if(c == '.')
						state = FINAL;
					else if(!isdigit(c))
						state = INITIAL;
					break;
				default:
					break;
			}
				break;
			default:
				break;
		}
	}

private:
	Type type;
	State state;
};


bool find_regex(std::string &line, bool or_operator)
{
	if(line.length() > 0)
	{
		if(or_operator)
		{
			Regexp regexp1(SINGLE);
			Regexp regexp2(OR_OPERATOR);
			int i = 0;
			do {
				regexp1.transition(line[i]);
				regexp2.transition(line[i]);
				i++;
				if(regexp1.getState() == FINAL ||
				   regexp2.getState() == FINAL ||
				   (i == line.length() && regexp1.getState() == DIGIT))
					return true;
			} while(i < line.length());
		}
		else
		{
			Regexp regexp(SINGLE);
			int i = 0;
			do {
				regexp.transition(line[i]);
				i++;
				if(regexp.getState() == FINAL ||
				   (i == line.length() && regexp.getState() == DIGIT))
					return true;
			} while(i < line.length());
		}
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
	if(argc < 2 || argc > 3)
	{
		fprintf(stderr, "Illegal number of arguments\n");
		exit(1);
	}
	
	bool or_operator = false;
	
	if(argc == 3)
	{
		if(!strcmp(argv[2], "--with-or-operator"))
			or_operator = true;
		else
		{
			fprintf(stderr, "Illegal argument: %s\n", argv[2]);
			exit(1);
		}
	}
	
	regex_match(argv[1], or_operator);
    return 0;
}
