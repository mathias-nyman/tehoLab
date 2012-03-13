#
# Concat1.py
#
# Created by Jukka Aro on 13.3.2012.
#

import sys

def concatenate(input_file):
	f = open(input_file, 'r')
	s = '';
	for line in f:
		s += line.rstrip()
	f.close()


# program entry:

if len(sys.argv) != 2:
	print "Illegal number of arguments"
	sys.exit()
concatenate(sys.argv[1])