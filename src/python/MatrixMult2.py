import sys
import os

def main():
    f = open(sys.argv[1])
    lines = f.readlines()
    f.close()
    result = 0
    dimension = int(sys.argv[2])
    matrix = []
    #TODO: this might not be the proper solution
    #      if input file is not in "matrix" format also
    for idx, line in enumerate(lines):
        if idx == dimension:
            break
        matrix[idx] = [int(i) for i in line.split()][:dimension]

    #TODO: how did matrix multiplication go again...?
    result = []
    dimension = len(matrix)
    for i in range(dimension):
        for j in range(dimension):
            result[i][j] = matrix[i][j] * matrix[j][i]

if __name__ == '__main__':
    main()
    print os.times(), 'TODO: which of these do we measure?'

