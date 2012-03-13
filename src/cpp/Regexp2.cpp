#include <string>
#include <istream>
#include <fstream>
#include <vector>
//#include <regex> //NOTE: see other note

using namespace std;
int main(int argv, char** argc) {
    ifstream inStream;
    inStream.open(argc[1]);

    bool dryRun = false;
    if (argv > 2 and argc[2] == "--dry-run")
        dryRun = true;
    if (argv > 2 and argc[3] == "--dry-run")
        dryRun = true;

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

    if (argv > 2 and argc[2] == "--dry-run")
        return 0;
    if (argv > 3 and argc[3] == "--dry-run")
        return 0;

    vector<string>::const_iterator it = lines.begin();
    vector<string>::const_iterator end = lines.end();
    for (; it != end; ++it) {
    }


    return 0;
}
