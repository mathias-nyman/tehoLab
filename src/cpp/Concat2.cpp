#include <string>
#include <istream>
#include <fstream>
#include <string.h>

using namespace std;
int main(int argv, char** argc) {
    ifstream inStream;
    inStream.open(argc[1]);
    bool dryRun = false;
    if (argv > 2 and not strcmp(argc[2], "--dry-run"))
        dryRun = true;

    string concatenated;
    string tmp;
    if (dryRun) {
        while (inStream.good()) {
            getline(inStream, tmp);
        }
    }
    else {
        while (inStream.good()) {
            getline(inStream, tmp);
                concatenated += tmp + '\n';
        }
    }
    inStream.close();

    return 0;
}
