#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_GRANULARITY 512

char* readFile(const char *filename)
{
	FILE* file = fopen(filename, "r");
	
	if(file == NULL)
	{
		return NULL;
	}
	
	// get file length and rewind
	fseek(file, 0L, SEEK_END);
	long fileLength = ftell(file);
	fseek(file, 0L, SEEK_SET);
	
	// allocate buffer
	char* buffer = (char*)malloc((fileLength + 1) * sizeof(char));
	
	// close file and bail if allocation fails
	if(buffer == NULL)
	{
		fclose(file);
		return NULL;
	}
	
	// copy file contents to memory and close file
	fread(buffer, sizeof(char), fileLength, file);
	fclose(file);
	
	return buffer;
}

int getLineCount(const char* buffer)
{
	int z = 1;
	char* pch;
	
	// Find first match
	pch = strchr(buffer, '\n');
	
	// Increment line count
	while(pch)
	{
		pch = strchr(pch + 1, '\n');
		z++;
	}
	
	return z;
}

char** splitToLines(char *buffer, int* lineCount)
{
	int allocatedLineCount = getLineCount(buffer);
	char** lines = (char**)malloc(allocatedLineCount * sizeof(char*));
	if(lines == NULL)
	{
		free(lines);
		return NULL;
	}
	
	lines[0] = buffer;
	*lineCount = 1;
	char* lastTokenFound = strpbrk(buffer, "\n");
	while(lastTokenFound != NULL && (*lineCount) < allocatedLineCount)
	{
		lines[*lineCount] = lastTokenFound + 1;
		
		// replace last lines last character (\n) with \0
		*(lines[*lineCount] - 1) = '\0';
		
		lastTokenFound = strpbrk(lines[*lineCount], "\n");
		
		(*lineCount)++;
	}
	
	// revert the last increment where no line was found anymore
	(*lineCount)--;
	
	return lines;
}

char* growOrKill(char* buffer, size_t newSize)
{
	char* newBuffer = (char*)realloc(buffer, newSize);
	if(newBuffer == NULL)
	{
		free(buffer);
	}
	
	return newBuffer;
}

int main(int argc, char **argv)
{
	// check argument count
	if(argc < 2 || argc > 3)
	{
		return EXIT_FAILURE;
	}
	
	int dryRun = 0;
	if(argc == 3)
	{
		if(strcmp("--dry-run", argv[2]) == 0)
		{
			dryRun = 1;
		}
		else
		{
			return EXIT_FAILURE;
		}
	}
	
	// read file into string
	char* buffer = readFile(argv[1]);
	if(buffer == NULL)
	{
		return EXIT_FAILURE;
	}
	
	// split string to lines
	int lineCount = 0;
	char** lines = splitToLines(buffer, &lineCount);
	if(lines == NULL)
	{
		return EXIT_FAILURE;
	}
	
	// run the concatenation test
	
	if(!dryRun)
	{
		// assuming it's not allowed to know the input length
		
		size_t resultBufferSize = BUFFER_GRANULARITY;
		size_t resultBufferUsed = 0;
		
		char* resultBuffer = growOrKill(NULL, resultBufferSize * sizeof(char));
		resultBuffer[0] = '\0';
		
		if(resultBuffer == NULL)
		{
			free(lines);
			free(buffer);
			return EXIT_FAILURE;
		}
		
		int i;
		for(i = 0; i < lineCount; i++)
		{
			size_t lineLength = strlen(lines[i]);
			
			// grow it need to...
			while(resultBufferUsed + lineLength + 1>= resultBufferSize)
			{
				resultBufferSize += BUFFER_GRANULARITY;
				resultBuffer = growOrKill(resultBuffer, resultBufferSize * sizeof(char));
				if(resultBuffer == NULL)
				{
					free(lines);
					free(buffer);
					return EXIT_FAILURE;
				}
			}
			
			strcat(resultBuffer, lines[i]);
			strcat(resultBuffer, "\n");
			resultBufferUsed += lineLength + 1;
			
			// debug print
			//printf("%s\n", lines[i]);
		}
		
		// debug print
		//printf("%s", resultBuffer);
		free(resultBuffer);
	}
	
	// free everything and exit
	free(lines);
	free(buffer);
	return EXIT_SUCCESS;
}
