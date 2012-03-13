import sys
import re
import os

def main():
    f = open(sys.argv[1])
    lines = f.readlines()
    f.close()

    if len(sys.argv) > 2 and sys.argv[2] == '--dry-run':
        return
    if len(sys.argv) > 3 and sys.argv[3] == '--dry-run':
        return

    #Pre-compile regexp before comparing to it
    #TODO: this should be excluded from "empty"-run
    if len(sys.argv) > 2 and sys.argv[2] == '--with-or-operator':
        pattern = re.compile(r"\d+|\w+\d+\.")
    else:
        pattern = re.compile(r"\d+")

    amountFound = 0
    for line in lines:
        match = pattern.search(line)
        if match is not None:
            amountFound = amountFound + 1

if __name__ == '__main__':
    main()
    print os.times(), 'TODO: which of these do we measure?'

