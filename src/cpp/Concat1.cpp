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

void concatenate(const char *input_file)
{
	std::ifstream ifs(input_file, std::ifstream::in);
	
	clock_t total = 0;
	std::string result;
	
	while(ifs.good())
	{
		std::string tmp;
		ifs >> tmp;
		clock_t start = clock();
		result.append(tmp);
		clock_t end = clock();
		total += end-start;
	}
	
	std::cout << ((double)total)/CLOCKS_PER_SEC << std::endl;
	
	ifs.close();
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
