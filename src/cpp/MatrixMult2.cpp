#include <string>
#include <istream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

template <typename T>
void matrixMult(ifstream& inStream, size_t dimension, bool dryRun) {
    vector<T> row(dimension, 0);
    vector<vector<T> > matrix(dimension, row);
    vector<vector<T> > result(dimension, row);

    string notNeeded;
    double number;
    size_t rowNr, colNr = -1;
    while (inStream.good() and ++rowNr < dimension) {
        while (++colNr < dimension) {
            inStream >> number;
            matrix[rowNr][colNr] = (T)number;
        }
        colNr = -1;
        getline(inStream, notNeeded);
    }
    inStream.close();

    if (dryRun)
        return;

    for (size_t i = 0; i < dimension ; ++i) {
        for (size_t j = 0; j < dimension ; ++j) {
            for (size_t k = 0; k < dimension ; ++k) {
                result[i][j] = result[i][j] + matrix[i][k] * matrix[k][j];
            }
        }
    }
}

int main(int argv, char** argc) {
    ifstream inStream;
    inStream.open(argc[1]);
    size_t dimension;
    sscanf(argc[2], "%zd", &dimension);

    bool dryRun = false;
    if (argv > 3 and not strcmp(argc[3], "--dry-run"))
        dryRun = true;
    if (argv > 4 and not strcmp(argc[4], "--dry-run"))
        dryRun = true;

    if (argv > 3 and not strcmp(argc[3], "--float")) {
        matrixMult<int>(inStream, dimension, dryRun);
    }
    else {
        matrixMult<float>(inStream, dimension, dryRun);
    }

    return 0;
}
