#include <string>
#include <istream>
#include <fstream>

using namespace std;
int main(int argv, char** argc) {
    ifstream inStream;
    inStream.open(argc[1]);

    string concatenated;
    string tmp;
    while (inStream.good()) {
        getline(inStream, tmp);
        concatenated += tmp + '\n';
    }
    inStream.close();

    return 0;
}
