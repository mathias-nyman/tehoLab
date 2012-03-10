import sys
import os

def main():
    f = open(sys.argv[1])
    lines = f.readlines()
    f.close()
    dimension = int(sys.argv[2])
    itemType = 1 if len(sys.argv) > 3 and sys.argv[3] == '--float' else 0
    matrix = []
    #TODO: this might not be the proper solution
    #      if input file is not in "matrix" format also
    if itemType == 0:
        for idx, line in enumerate(lines):
            if idx == dimension:
                break
                matrix[idx] = [int(i) for i in line.split()][:dimension]
    else:
        for idx, line in enumerate(lines):
            if idx == dimension:
                break
            matrix[idx] = [float(i) for i in line.split()][:dimension]

    #TODO: how did matrix multiplication go again...?
    result = []
    dimension = len(matrix)
    for i in range(dimension):
        for j in range(dimension):
            for k in range(dimension):
                result[i][j] = result[i][j] + matrix[i][k] * matrix[k][j]

if __name__ == '__main__':
    main()
    print os.times(), 'TODO: which of these do we measure?'

