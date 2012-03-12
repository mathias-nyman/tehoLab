#include <string>
#include <istream>
#include <fstream>
#include <vector>
//#include <regex> //NOTE: see other note

using namespace std;
int main(int argv, char** argc) {
    ifstream inStream;
    inStream.open(argc[1]);

    //NOTE: C++0x standard's regex has not been done yet
    //      See url for up-to-date information:
    //      http://gcc.gnu.org/onlinedocs/libstdc++/manual/status.html#status.iso.200x
    //regex pattern("\\d+");
    if (argv > 2 and argc[2] == "--with-or-operator") {
        //pattern = regex("\\d+|\\w+\\d+\\.");
    }

    vector<string> lines;
    string line;
    while (inStream.good()) {
        getline(inStream, line);
        lines.push_back(line + '\n');
    }
    inStream.close();

    vector<string>::const_iterator it = lines.begin();
    vector<string>::const_iterator end = lines.end();
    for (; it != end; ++it) {
    }


    return 0;
}
