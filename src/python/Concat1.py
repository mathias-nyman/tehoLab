#
# Concat1.py
#
# Created by Jukka Aro on 13.3.2012.
#

import sys

def concatenate(input_file, dry_run):
	f = open(input_file, 'r')
	if dry_run:
		for line in f:
			pass
	else:
		s = '';
		for line in f:
			s += line
	f.close()


# program entry:

if len(sys.argv) < 2 or len(sys.argv) > 3:
	print "Illegal number of arguments"
	sys.exit()
if len(sys.argv)  == 3 and sys.argv[2] == '--dry-run':
	dry_run = True
else:
	dry_run = False
	
concatenate(sys.argv[1], dry_run)