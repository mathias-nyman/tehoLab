#
# Regexp1.py
#
# Created by Jukka Aro on 13.3.2012.
#

import sys
import re

def regexp_match(input_file, or_operator):
	f = open(input_file, 'r')
	if or_operator:
		prog = re.compile(r"\d+|\w+\d+\.")
	else:
		prog = re.compile(r"\d+")
	cnt = 0
	for line in f:
		if(prog.search(line) != None):
			cnt += 1
	f.close()


# program entry:

if len(sys.argv) < 2 or len(sys.argv) > 3:
	print "Illegal number of arguments"
	sys.exit()
	
if len(sys.argv) == 3:
	if sys.argv[2] == '--with-or-operator':
		or_operator = True
	else:
		print "Illegal argument: " + sys.argv[2]
		sys.exit()
else:
	or_operator = False
	
regexp_match(sys.argv[1], or_operator)
