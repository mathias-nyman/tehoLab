/*
 *  MatrixMult1.c
 *  
 *
 *  Created by Jukka Aro on 9.3.2012.
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define INDEX(array, dim, row, col) (*((array)+(dim)*(row)+(col)))

float scan_float(FILE *f)
{
	float fl = 0;
	fscanf(f, "%f", &fl);
	return fl;
}

void read_input_file_int(const char *input_file, int dim, int *in_matrix)
{
	FILE *f = fopen(input_file, "r");
	
	if(f != 0)
	{
		int i;
		
		for(i = 0; i < dim*dim; i++)
			in_matrix[i] = (int)scan_float(f);;
		
		fclose(f);
	}
}

void read_input_file_float(const char *input_file, int dim, float *in_matrix)
{
	FILE *f = fopen(input_file, "r");
	
	if(f != 0)
	{
		int i;
		
		for(i = 0; i < dim*dim; i++)
			in_matrix[i] = scan_float(f);;
		
		fclose(f);
	}
}

int* multiply_int_matrix(const char *input_file, int dim)
{
	int *in_matrix = malloc(dim*dim*sizeof(int));
	
	if(!in_matrix)
	{
		fprintf(stderr, "Malloc failed\n");
		exit(1);
	}
	
	read_input_file_int(input_file, dim, in_matrix);
	
	int *out_matrix = malloc(dim*dim*sizeof(int));
	
	if(!out_matrix)
	{
		fprintf(stderr, "Malloc failed\n");
		exit(1);
	}
	
	int i, j, k;
	
	for(i = 0; i < dim; i++)
	{
		for(j = 0; j < dim; j++)
		{
			int res = 0;
			for(k = 0; k < dim; k++)
				res += INDEX(in_matrix, dim, i, k)*INDEX(in_matrix, dim, k, j);
			INDEX(out_matrix, dim, i, j) = res;
		}
	}
	
	free(in_matrix);
	return(out_matrix);
}

float* multiply_float_matrix(const char *input_file, int dim)
{
	float *in_matrix = malloc(dim*dim*sizeof(float));
	
	if(!in_matrix)
	{
		fprintf(stderr, "Malloc failed\n");
		exit(1);
	}
	
	read_input_file_float(input_file, dim, in_matrix);
	
	float *out_matrix = malloc(dim*dim*sizeof(float));
	
	if(!out_matrix)
	{
		fprintf(stderr, "Malloc failed\n");
		exit(1);
	}
	
	int i, j, k;
	
	for(i = 0; i < dim; i++)
	{
		for(j = 0; j < dim; j++)
		{
			float res = 0;
			for(k = 0; k < dim; k++)
				res += INDEX(in_matrix, dim, i, k)*INDEX(in_matrix, dim, k, j);
			INDEX(out_matrix, dim, i, j) = res;
		}
	}
	
	free(in_matrix);
	return(out_matrix);
}

void parse_params(int argc, char **argv, char **input_file, int *dim, int *is_float)
{
	if(argc < 3 || argc > 4)
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
	{
		float *result = multiply_float_matrix(input_file, dim);
		int i, j;
		for(i = 0; i < dim; i++)
			for(j = 0; j<  dim; j++)
				printf("%f ", INDEX(result, dim, i, j));
		free(result);
	}
	else
	{
		int *result = multiply_int_matrix(input_file, dim);
		int i, j;
		for(i = 0; i < dim; i++)
			for(j = 0; j<  dim; j++)
				printf("%d ", INDEX(result, dim, i, j));
		free(result);
	}

    return 0;
}
