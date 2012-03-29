#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

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

int main(int argc, char **argv)
{
	// check argument count
	if(argc < 2 || argc > 4)
	{
		return EXIT_FAILURE;
	}
	
	// undefined
	int dryRun = -1;
	int withOrOperator = -1;
	
	// check provided arguments
	int argNum;
	for(argNum = 2; argNum < argc; argNum++)
	{
		if(strcmp("--dry-run", argv[argNum]) == 0)
		{
			if(dryRun == -1)
			{
				dryRun = 1;
			}
			else
			{
				return EXIT_FAILURE;
			}
		}
		else if(strcmp("--with-or-operator", argv[argNum]) == 0)
		{
			if(withOrOperator == -1)
			{
				withOrOperator = 1;
			}
			else
			{
				return EXIT_FAILURE;
			}
		}
		else
		{
			return EXIT_FAILURE;
		}
	}
	// default to 0 if not provided
	if(dryRun == -1)
	{
		dryRun = 0;
	}
	if(withOrOperator == -1)
	{
		withOrOperator = 0;
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
	
	// run the regexp test
	
	const char* regex;
	if(withOrOperator)
	{
		regex = "[0-9]+|[a-zA-Z_0-9]+[0-9]+\\.";
	}
	else
	{
		regex = "[0-9]+";
	}
	
	// compile regexp matcher
	regex_t patternBuffer;
	
	// REG_NOSUB: only need to know that it does in fact match, not where it matches
	// REG_EXTENDED: support "|" and "+" operator
	int regcompRet = regcomp(&patternBuffer, regex, REG_NOSUB | REG_EXTENDED);
	if(regcompRet)
	{
		free(lines);
		free(buffer);
		return EXIT_FAILURE;
	}
	
	// iterate each line
	int countMatches = 0;
	int i;
	
	if(dryRun)
	{
		for(i = 0; i < lineCount; i++);
	}
	else
	{
		for(i = 0; i < lineCount; i++)
		{
			//printf("%s\n", lines[i]);
			
			int regexecRet = regexec(&patternBuffer, lines[i], 0, NULL, 0);
			if(regexecRet == 0)
			{
				countMatches++;
				//printf("%s\n", lines[i]);
			}
			else if(regexecRet != REG_NOMATCH)
			{
				// undefined behaviour
				regfree(&patternBuffer);
				free(lines);
				free(buffer);
				return EXIT_FAILURE;
			}
		}
	}
	
	regfree(&patternBuffer);
	
	//printf("%d", countMatches);
	
	// free everything and exit
	free(lines);
	free(buffer);
	return EXIT_SUCCESS;
}
