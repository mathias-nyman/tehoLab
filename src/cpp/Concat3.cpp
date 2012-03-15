#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::runtime_error;
using std::ifstream;
using std::vector;

class Configuration
{
	public:
	
	string* filename;
	bool dryRun;
	
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
			else
			{
				throw runtime_error("Unknown argument: \"" + args[i] + "\".");
			}
		}
		
		this->dryRun = dryRun;
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
	
	if(!configuration.dryRun)
	{
		string result;
		for(vector<string>::const_iterator iterator = lines->begin(); iterator != lines->end(); iterator++)
		{
			result.append(*iterator + '\n');
		}
		
		cout << result << endl;
	}
	
	delete lines;
	
	return 0;
}
