#include <string>
#include <istream>
#include <fstream>
#include <vector>
#include <string.h>
#include <boost/regex.hpp>

using namespace std;
int main(int argv, char** argc) {
    ifstream inStream;
    inStream.open(argc[1]);

    bool dryRun = false;
    if (argv > 2 and not strcmp(argc[2], "--dry-run"))
        dryRun = true;
    if (argv > 3 and not strcmp(argc[3], "--dry-run"))
        dryRun = true;

    boost::regex pattern("\\d+");
    if (argv > 2 and argc[2] == "--with-or-operator") {
        boost::regex pattern("\\d+|\\w+\\d+\\.");
    }

    vector<string> lines;
    string line;
    while (inStream.good()) {
        getline(inStream, line);
        lines.push_back(line + '\n');
    }
    inStream.close();

    if (dryRun)
        return 0;

    size_t amountFound = 0;
    boost::smatch matches;

    vector<string>::const_iterator it = lines.begin();
    vector<string>::const_iterator end = lines.end();
    for (; it != end; ++it) {
        if (boost::regex_search(*it, pattern)) {
            amountFound++;
        }
    }

    return 0;
}
