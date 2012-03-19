#include <string>
#include <istream>
#include <fstream>
#include <vector>
#include <boost/regex.hpp>

using namespace std;
int main(int argv, char** argc) {
    ifstream inStream;
    inStream.open(argc[1]);

    bool dryRun = false;
    if (argv > 2 and argc[2] == "--dry-run")
        dryRun = true;
    if (argv > 2 and argc[3] == "--dry-run")
        dryRun = true;

    if (argv > 2 and argc[2] == "--with-or-operator") {
        boost::regex pattern("\\d+|\\w+\\d+\\.");
    }
    else {
        boost::regex pattern("\\d+");
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
