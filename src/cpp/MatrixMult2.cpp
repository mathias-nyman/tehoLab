#include <string>
#include <istream>
#include <fstream>
#include <vector>

using namespace std;

template <typename T>
void matrixMult(ifstream& inStream, size_t dimension) {
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
    sscanf(argc[2], "%d", &dimension);

    if (argv > 3 and argc[3] == "--float") {
        matrixMult<int>(inStream, dimension);
    }
    else {
        matrixMult<float>(inStream, dimension);
    }

    return 0;
}
