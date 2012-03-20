#
# Regexp1.py
#
# Created by Jukka Aro on 13.3.2012.
#

import sys
import re

def regexp_match(input_file, or_operator, dry_run):
	f = open(input_file, 'r')
	if dry_run:
		for line in f:
			pass
	else:
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

if len(sys.argv) < 2 or len(sys.argv) > 4:
	print "Illegal number of arguments"
	sys.exit()

or_operator = False
dry_run = False

if len(sys.argv) == 3:
	if sys.argv[2] == '--with-or-operator':
		or_operator = True
	elif sys.argv[2] == '--dry-run':
		dry_run = True
	else:
		print "Illegal argument: " + sys.argv[2]
		sys.exit()
if len(sys.argv) == 4:
	if sys.argv[2] == '--with-or-operator' and sys.argv[3] == '--dry-run':
		or_operator = True
		dry_run = True
	else:
		print "Illegal arguments: " + sys.argv[2] + " " + sys.argv[3]
		sys.exit()
	
regexp_match(sys.argv[1], or_operator, dry_run)
