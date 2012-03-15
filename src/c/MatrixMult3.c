#include <stdio.h>
#include <stdlib.h>

int skipRestOfLine(FILE* file)
{
	int value;
	do
	{
		value = fgetc(file);
		
		if(value == '\n')
		{
			return 0;
		}
		else if(value == EOF)
		{
			fprintf(stderr, "can't open file\n");
			return -1;
		}
	}
	while(1);
	
	return 0;
}

int fillIntegerMatrixFromFile(const char* filename, int* matrix, int dimension)
{
	FILE* file = fopen(filename, "r");
	if(file == NULL)
	{
		fprintf(stderr, "can't open file\n");
		return -1;
	}
	
	int rowIndex;
	int cellIndex;
	for(rowIndex = 0; rowIndex < dimension; rowIndex++)
	{
		for(cellIndex = 0; cellIndex < dimension; cellIndex++)
		{
			float temp;
			int numRead = fscanf(file, "%f", &temp);
			if(numRead != 1)
			{
				fprintf(stderr, "can't read integer, ret %d\n", numRead);
				fclose(file);
				return -1;
			}
			
			matrix[rowIndex * dimension + cellIndex] = (int)temp;
			//printf("%d   ", matrix[rowIndex * dimension + cellIndex]);
		}
		//printf("\n");
		if(skipRestOfLine(file) != 0)
		{
			fprintf(stderr, "can't skipRestOfLine\n");
			fclose(file);
			return -1;
		}
	}
	//printf("\n\n");
	
	fclose(file);
	return 0;
}

void multiplyInteger(int* a, int* b, int* result, int dimension)
{
	int row_index;
	for(row_index = 0; row_index < dimension; row_index++)
	{
		int cell_index;
		for(cell_index = 0; cell_index < dimension; cell_index++)
		{
			int k;
			result[row_index * dimension + cell_index] = 0;
			for(k = 0; k < dimension; k++)
			{
				result[row_index * dimension + cell_index] += a[row_index * dimension + k] * b[k * dimension + cell_index];
			}
			//printf("%d   ", result[row_index * dimension + cell_index]);
		}
		//printf("\n");
		//printf("%d\n", row_index);
	}
	//printf("\n\n");
}

int fillFloatMatrixFromFile(const char* filename, float* matrix, int dimension)
{
	FILE* file = fopen(filename, "r");
	if(file == NULL)
	{
		fprintf(stderr, "can't open file\n");
		return -1;
	}
	
	int rowIndex;
	int cellIndex;
	for(rowIndex = 0; rowIndex < dimension; rowIndex++)
	{
		for(cellIndex = 0; cellIndex < dimension; cellIndex++)
		{
			float temp;
			int numRead = fscanf(file, "%f", &temp);
			if(numRead != 1)
			{
				fprintf(stderr, "can't read integer, ret %d\n", numRead);
				fclose(file);
				return -1;
			}
			
			matrix[rowIndex * dimension + cellIndex] = temp;
			//printf("%f   ", matrix[rowIndex * dimension + cellIndex]);
		}
		//printf("\n");
		if(skipRestOfLine(file) != 0)
		{
			fprintf(stderr, "can't skipRestOfLine\n");
			fclose(file);
			return -1;
		}
	}
	//printf("\n\n");
	
	fclose(file);
	return 0;
}

void multiplyFloat(float* a, float* b, float* result, int dimension)
{
	int row_index;
	for(row_index = 0; row_index < dimension; row_index++)
	{
		int cell_index;
		for(cell_index = 0; cell_index < dimension; cell_index++)
		{
			int k;
			result[row_index * dimension + cell_index] = 0;
			for(k = 0; k < dimension; k++)
			{
				result[row_index * dimension + cell_index] += a[row_index * dimension + k] * b[k * dimension + cell_index];
			}
			//printf("%f   ", result[row_index * dimension + cell_index]);
		}
		//printf("\n");
		//printf("%d\n", row_index);
	}
	//printf("\n\n");
}

int main(int argc, char **argv)
{
	// check argument count
	if(argc < 3 || argc > 5)
	{
		fprintf(stderr, "bad arguments\n");
		return EXIT_FAILURE;
	}
	
	// undefined
	int dryRun = -1;
	int asFloat = -1;
	
	// check provided arguments
	int argNum;
	for(argNum = 3; argNum < argc; argNum++)
	{
		if(strcmp("--dry-run", argv[argNum]) == 0)
		{
			if(dryRun == -1)
			{
				dryRun = 1;
			}
			else
			{
				fprintf(stderr, "bad argument\n");
				return EXIT_FAILURE;
			}
		}
		else if(strcmp("--float", argv[argNum]) == 0)
		{
			if(asFloat == -1)
			{
				asFloat = 1;
			}
			else
			{
				fprintf(stderr, "bad argument\n");
				return EXIT_FAILURE;
			}
		}
		else
		{
			fprintf(stderr, "bad argument\n");
			return EXIT_FAILURE;
		}
	}
	// default to 0 if not provided
	if(dryRun == -1)
	{
		dryRun = 0;
	}
	if(asFloat == -1)
	{
		asFloat = 0;
	}
	
	int dimension;
	if(sscanf(argv[2], "%d", &dimension) != 1)
	{
		fprintf(stderr, "dimension not integer\n");
		return EXIT_FAILURE;
	}
	
	if(asFloat)
	{
		float* input = (float*)malloc(dimension * dimension * sizeof(float));
		if(input == NULL)
		{
			fprintf(stderr, "failed to allocate memory for input\n");
			return EXIT_FAILURE;
		}
		
		float* result = (float*)malloc(dimension * dimension * sizeof(float));
		if(result == NULL)
		{
			fprintf(stderr, "failed to allocate memory for result\n");
			return EXIT_FAILURE;
		}
		
		if(fillFloatMatrixFromFile(argv[1], input, dimension))
		{
			fprintf(stderr, "can't read matrix\n");
			return EXIT_FAILURE;
		}
		
		// run the matrix test
		if(!dryRun)
		{
			multiplyFloat(input, input, result, dimension);
		}
		
		// free everything and exit
		free(result);
		free(input);
	}
	else
	{
		int* input = (int*)malloc(dimension * dimension * sizeof(int));
		if(input == NULL)
		{
			fprintf(stderr, "failed to allocate memory for input\n");
			return EXIT_FAILURE;
		}
		
		int* result = (int*)malloc(dimension * dimension * sizeof(int));
		if(result == NULL)
		{
			fprintf(stderr, "failed to allocate memory for result\n");
			return EXIT_FAILURE;
		}
		
		if(fillIntegerMatrixFromFile(argv[1], input, dimension))
		{
			fprintf(stderr, "can't read matrix\n");
			return EXIT_FAILURE;
		}
		
		// run the matrix test
		if(!dryRun)
		{
			multiplyInteger(input, input, result, dimension);
		}
		
		// free everything and exit
		free(result);
		free(input);
	}
	
	return EXIT_SUCCESS;
}
