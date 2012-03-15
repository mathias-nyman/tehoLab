#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>

using std::string;
using std::stringstream;
using std::cout;
using std::endl;
using std::runtime_error;
using std::ifstream;

class Configuration
{
	public:
	
	string* filename;
	int dimension;
	bool dryRun;
	bool asFloat;
	
	Configuration(int argc, char** argv)
	{
		string args[argc - 1];
		
		for(int i = 1; i < argc; i++)
		{
			args[i - 1] = string(argv[i]);
		}
		
		if(argc < 2 || args[0].length() == 0 || args[1].length() == 0)
		{
			throw runtime_error("File name must be provided in the first argument, and dimension in the second");
		}
		
		this->filename = new string(args[0]);
		
		stringstream dimension_stringstream(argv[2]);
		dimension_stringstream >> this->dimension;
		if(dimension_stringstream.fail())
		{
			throw runtime_error("dimension not an integer");
		}
		bool dryRun = false;
		bool asFloat = false;
		
		for(int i = 2; i < argc - 1; i++)
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
			else if(args[i].compare("--float") == 0)
			{
				if(asFloat)
				{
					throw runtime_error("Argument \"--float\" provided multiple times.");
				}
				else
				{
					asFloat = true;
				}
			}
			else
			{
				throw runtime_error("Unknown argument: \"" + args[i] + "\".");
			}
		}
		
		this->dryRun = dryRun;
		this->asFloat = asFloat;
	}
	
	~Configuration()
	{
		delete this->filename;
	}
};

class NumberSource
{
	private:
	
	ifstream* inputFile;
	
	public:
	
	NumberSource(string filename)
	{
		this->inputFile = new ifstream(filename.c_str());
	}
	
	~NumberSource()
	{
		this->inputFile->close();
		delete this->inputFile;
	}
	
	void skipRestOfLine()
	{
		if(this->inputFile->is_open())
		{
			while(this->inputFile->good())
			{
				char c = this->inputFile->get();
				
				if(c == '\n')
				{
					return;
				}
			}
		}
		
		throw runtime_error("can't read number from input file");
	}
	
	int getInt()
	{
		return (int)this->getFloat();
	}
	
	float getFloat()
	{
		float number;
		
		if(this->inputFile->is_open() && this->inputFile->good())
		{
			*this->inputFile >> number;
			if(this->inputFile->fail())
			{
				throw runtime_error("bad number from input file");
			}
			
			return number;
		}
		
		throw runtime_error("can't read number from input file");
	}
};

template<typename T>
class Matrix
{
	private:
	T* data;
	int dimension;
	
	public:
	
	Matrix(int dimension, NumberSource* numberSource = NULL) : dimension(dimension)
	{
		this->data = new T[dimension * dimension];
		
		if(numberSource != NULL)
		{
			for(int row_index = 0; row_index < getDimension(); row_index++)
			{
				for(int cell_index = 0; cell_index < getDimension(); cell_index++)
				{
					this->data[row_index * getDimension() + cell_index] = (T)numberSource->getFloat();
					
					//cout << this->data[row_index * getDimension() + cell_index] << endl;
				}
				
				numberSource->skipRestOfLine();
			}
		}
	}
	
	~Matrix()
	{
		delete this->data;
	}
	
	int getDimension()
	{
		return this->dimension;
	}
	
	static Matrix* multiply(Matrix& a, Matrix& b)
	{
		if(a.getDimension() != b.getDimension())
		{
			throw runtime_error("Matrices must be of the same dimension");
		}
		
		Matrix* ret = new Matrix(a.getDimension());
		
		for(int row_index = 0; row_index < ret->getDimension(); row_index++)
		{
			for(int cell_index = 0; cell_index < ret->getDimension(); cell_index++)
			{
				ret->data[row_index * ret->getDimension() + cell_index] = 0;
				for(int k = 0; k < ret->getDimension(); k++)
				{
					ret->data[row_index * ret->getDimension() + cell_index] += a.data[row_index * ret->getDimension() + k] * b.data[k * ret->getDimension() + cell_index];
				}
			}
		}
		
		return ret;
	}
	
	void print()
	{
		for(int row_index = 0; row_index < getDimension(); row_index++)
		{
			for(int cell_index = 0; cell_index < getDimension(); cell_index++)
			{
				cout << this->data[row_index * getDimension() + cell_index] << "       ";
			}
			
			cout << endl;
		}
	}
};

int main(int argc, char** argv)
{
	Configuration configuration = Configuration(argc, argv);
	
	NumberSource numberSource = NumberSource(*configuration.filename);
	
	if(configuration.asFloat)
	{
		Matrix<float> input(configuration.dimension, &numberSource);
		
		if(!configuration.dryRun)
		{
			Matrix<float>* result = Matrix<float>::multiply(input, input);
			
			//result->print();
			
			delete result;
		}
	}
	else
	{
		Matrix<int> input(configuration.dimension, &numberSource);
		
		if(!configuration.dryRun)
		{
			Matrix<int>* result = Matrix<int>::multiply(input, input);
			//result->print();
			
			delete result;
		}
	}
	
	//cout << "done" << endl;
	return 0;
}
