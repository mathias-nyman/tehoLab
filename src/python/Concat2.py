import sys
import os

def main():
    f = open(sys.argv[1])
    lines = f.readlines()
    f.close()
    concatenated = ''.join(lines)

if __name__ == '__main__':
    main()
    print os.times(), 'TODO: which of these do we measure?'

