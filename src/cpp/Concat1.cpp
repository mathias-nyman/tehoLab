/*
 *  Concat1.cpp
 *  
 *
 *  Created by Jukka Aro on 11.3.2012.
 *
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

void concatenate(const char *input_file, bool dry_run)
{
	std::ifstream ifs(input_file, std::ifstream::in);
	
	if(dry_run)
	{
		while(ifs.good())
		{
			std::string tmp;
			ifs >> tmp;
		}
	}
	else
	{
		std::string result;
		while(ifs.good())
		{
			std::string tmp;
			ifs >> tmp;
			result.append(tmp);
		}
	}

	ifs.close();
}

int main(int argc, char **argv)
{
	bool dry_run = false;
	
	switch(argc)
	{
		case 2:
			break;
		case 3:
			if(!strcmp(argv[2], "--dry-run"))
				dry_run = true;
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
