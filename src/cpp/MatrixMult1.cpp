/*
 *  MatrixMult1.cpp
 *  
 *
 *  Created by Jukka Aro on 11.3.2012.
 *
 */
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

#define INDEX(vector, dim, row, col) ((vector)[(dim)*(row)+(col)])
#define FLOATS_PER_ROW 5000

template<typename T>
void read_input_file(const char *input_file, int dim, std::vector<T> *in_matrix)
{
	std::ifstream ifs(input_file, std::ifstream::in);
	
	for(int i = 0; i < dim; i++)
	{
		int j = 0;
		for(; j < dim; j++)
		{
			float tmp;
			ifs >> tmp;
			INDEX(*in_matrix, dim, i, j) = (T)tmp;
		}
		if(j < FLOATS_PER_ROW)
		{
			std::string foo;
			getline(ifs, foo);
		}
	}
	
	ifs.close();
}

template<typename T>
void multiply_matrix(const char *input_file, int dim, bool dry_run)
{
	std::vector<T> *in_matrix = new std::vector<T>(dim*dim);
	
	if(!in_matrix)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}
	
	read_input_file(input_file, dim, in_matrix);
	
	if(dry_run) { delete in_matrix; return; }
	
	std::vector<T> *out_matrix = new std::vector<T>(dim*dim);
	
	if(!out_matrix)
	{
		fprintf(stderr, "Malloc failed\n");
		delete in_matrix;
		exit(1);
	}
	
	for(int i = 0; i < dim; i++)
	{
		for(int j = 0; j < dim; j++)
		{
			T res = 0;
			for(int k = 0; k < dim; k++)
				res += INDEX(*in_matrix, dim, i, k)*INDEX(*in_matrix, dim, k, j);
			INDEX(*out_matrix, dim, i, j) = res;
		}
	}
	
	delete in_matrix;
	delete out_matrix;
}

void parse_params(int argc, char **argv, char **input_file, int &dim, bool &is_float, bool &dry_run)
{
	switch(argc)
	{
		case 3:
			break;
		case 4:
			if(!strcmp(argv[3], "--float"))
				is_float = true;
			else
			{
				if(!strcmp(argv[3], "--dry-run"))
					dry_run = true;
				else
				{
					fprintf(stderr, "Illegal argument: %s\n", argv[3]);
					exit(1);
				}
			}
			break;
		case 5:
			if(!strcmp(argv[3], "--float") && !strcmp(argv[4], "--dry-run"))
			{
				is_float = true;
				dry_run = true;
			}
			else
			{
				fprintf(stderr, "Illegal arguments: %s %s\n", argv[3], argv[4]);
				exit(1);
			}
			break;
		default:
			fprintf(stderr, "Illegal number of arguments\n");
			exit(1);
	}
	
	*input_file = argv[1];
	
	if((dim = atoi(argv[2])) == 0)
	{
		fprintf(stderr, "Illegal argument: %s\n", argv[2]);
		exit(1);
	}
}

int main(int argc, char **argv)
{
	bool is_float = false, dry_run = false;
	int dim = 0;
	char *input_file;
	
	parse_params(argc, argv, &input_file, dim, is_float, dry_run);
	
	if(is_float)
		multiply_matrix<float>(input_file, dim, dry_run);
	else
		multiply_matrix<int>(input_file, dim, dry_run);
	
    return 0;
}
