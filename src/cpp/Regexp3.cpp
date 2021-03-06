#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <boost/regex.hpp>

using std::string;
using std::cout;
using std::endl;
using std::runtime_error;
using std::ifstream;
using std::vector;
using boost::regex;
using boost::regex_search;

class Configuration
{
	public:
	
	string* filename;
	bool dryRun;
	bool withOrOperator;
	
	Configuration(int argc, char** argv)
	{
		string args[argc - 1];
		
		for(int i = 1; i < argc; i++)
		{
			args[i - 1] = string(argv[i]);
		}
		
		if(argc < 1 || args[0].length() == 0)
		{
			throw runtime_error("File name must be provided in the first argument, and dimension in the second");
		}
		
		this->filename = new string(args[0]);
		
		bool dryRun = false;
		bool withOrOperator = false;
		
		for(int i = 1; i < argc - 1; i++)
		{
			if(args[i].compare("--dry-run") == 0)
			{
				if(dryRun)
				{
					throw runtime_error("Argument \"--dry-run\" provided multiple times.");
				}
				else
				{
					dryRun = true;
				}
			}
			else if(args[i].compare("--with-or-operator") == 0)
			{
				if(withOrOperator)
				{
					throw runtime_error("Argument \"--with-or-operator\" provided multiple times.");
				}
				else
				{
					withOrOperator = true;
				}
			}
			else
			{
				throw runtime_error("Unknown argument: \"" + args[i] + "\".");
			}
		}
		
		this->dryRun = dryRun;
		this->withOrOperator = withOrOperator;
	}
	
	~Configuration()
	{
		delete this->filename;
	}
};

vector<string>* getLines(string filename)
{
	ifstream inputFile(filename.c_str());
	
	vector<string>* lines = new vector<string>();
	
	if(inputFile.is_open())
	{
		while(inputFile.good())
		{
			string temp;
			getline(inputFile, temp);
			
			lines->push_back(temp);
		}
		
		return lines;
	}
	
	inputFile.close();
	
	throw runtime_error("can't read number from input file");
}

int main(int argc, char** argv)
{
	Configuration configuration = Configuration(argc, argv);
	
	vector<string>* lines = getLines(*configuration.filename);
	
	// run test
	
	string patternString;
	if(configuration.withOrOperator)
	{
		patternString = "\\d+|\\w+\\d+\\.";
	}
	else
	{
		patternString = "\\d+";
	}
	
	regex pattern(patternString);
	
	int countMatches = 0;
	if(configuration.dryRun)
	{
		for(vector<string>::const_iterator iterator = lines->begin(); iterator != lines->end(); iterator++);
	}
	else
	{
		for(vector<string>::const_iterator iterator = lines->begin(); iterator != lines->end(); iterator++)
		{
			if(regex_search(*iterator, pattern))
			{
				countMatches++;
			}
		}
	}
	
	//cout << countMatches << endl;
	
	delete lines;
	
	//cout << "done" << endl;
	return 0;
}
