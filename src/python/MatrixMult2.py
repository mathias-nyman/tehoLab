import sys

def main():
    f = open(sys.argv[1])
    lines = f.readlines()
    f.close()
    dimension = int(sys.argv[2])
    itemType = 1 if len(sys.argv) > 3 and sys.argv[3] == '--float' else 0
    matrix = [0]*dimension

    if itemType == 0:
        for idx, line in enumerate(lines):
            if idx == dimension:
                break
            matrix[idx] = [int(float(i)) for i in line.split()][:dimension]
    else:
        for idx, line in enumerate(lines):
            if idx == dimension:
                break
            matrix[idx] = [float(i) for i in line.split()][:dimension]

    if len(sys.argv) > 3 and sys.argv[3] == '--dry-run':
        return
    if len(sys.argv) > 4 and sys.argv[4] == '--dry-run':
        return

    result = [[0]*dimension]*dimension
    for i in range(dimension):
        for j in range(dimension):
            for k in range(dimension):
                result[i][j] = result[i][j] + matrix[i][k] * matrix[k][j]

if __name__ == '__main__':
    main()

