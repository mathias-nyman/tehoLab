import sys

def main():
    f = open(sys.argv[1])
    lines = f.readlines()
    f.close()
    if len(sys.argv) > 2 and sys.argv[2] == '--dry-run':
        return
    concatenated = ''.join(lines)

if __name__ == '__main__':
    main()

