#include <string>
#include <istream>
#include <fstream>
#include <vector>

using namespace std;

template <typename T>
void matrixMult(ifstream& inStream, vector<vector<T> > matrix, size_t dimension) {
    string notNeeded;
    double number;
    size_t rowNr = -1;
    size_t colNr = -1;
    while (inStream.good() and ++rowNr < dimension) {
        while (++colNr < dimension) {
            inStream >> number;
            matrix[rowNr][colNr] = (T)number;
        }
        colNr = -1;
        getline(inStream, notNeeded);
    }
    inStream.close();

    //TODO: matrix multiplication; this does not work..
    /*
    vector<vector<T> >::const_iterator it = matrix.begin();
    vector<vector<T> >::const_iterator end = matrix.end();
    for (; it != end; ++it) {
    }
    */
}

int main(int argv, char** argc) {
    ifstream inStream;
    inStream.open(argc[1]);
    size_t dimension;
    sscanf(argc[2], "%d", &dimension);

    if (argv > 3 and argc[3] == "--float") {
        vector<double> row(dimension, 0);
        vector<vector<double> > matrix(dimension, row);
        matrixMult(inStream, matrix, dimension);
    }
    else {
        vector<int> row(dimension, 0);
        vector<vector<int> > matrix(dimension, row);
        matrixMult(inStream, matrix, dimension);
    }

    return 0;
}
