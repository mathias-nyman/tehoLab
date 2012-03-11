/*
 *  MatrixMult1.cpp
 *  
 *
 *  Created by Jukka Aro on 11.3.2012.
 *
 */
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>

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
		for(; j < FLOATS_PER_ROW; j++)
		{
			float foo;
			ifs >> foo;
		}
	}
	
	ifs.close();
}

template<typename T>
void multiply_matrix(const char *input_file, int dim)
{
	std::vector<T> *in_matrix = new std::vector<T>(dim*dim);
	
	if(!in_matrix)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}
	
	read_input_file(input_file, dim, in_matrix);
	
	std::vector<T> *out_matrix = new std::vector<T>(dim*dim);
	
	if(!out_matrix)
	{
		fprintf(stderr, "Malloc failed\n");
		delete in_matrix;
		exit(1);
	}
	
	clock_t start = clock();
	
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
	
	clock_t end = clock();
	std::cout << dim << " " << (double)(end-start)/CLOCKS_PER_SEC << std::endl;
	
	delete in_matrix;
	delete out_matrix;
}

void parse_params(int argc, char **argv, char **input_file, int *dim, int *is_float)
{
	if(argc < 3 || argc > 5)
	{
		fprintf(stderr, "Illegal number of arguments\n");
		exit(1);
	}
	
	*input_file = argv[1];
	
	if((*dim = atoi(argv[2])) == 0)
	{
		fprintf(stderr, "Illegal argument: %s\n", argv[2]);
		exit(1);
	}
	
	if(argc == 4)
	{
		if(!strcmp(argv[3], "--float"))
			*is_float = 1;
		else
		{
			fprintf(stderr, "Illegal argument: %s\n", argv[3]);
			exit(1);
		}
	}
}

int main(int argc, char **argv)
{
	int is_float = 0, dim = 0;
	char *input_file;
	
	parse_params(argc, argv, &input_file, &dim, &is_float);
	
	if(is_float)
		multiply_matrix<float>(input_file, dim);
	else
		multiply_matrix<int>(input_file, dim);
	
    return 0;
}
