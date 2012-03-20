#
# MatrixMult1.py
#
# Created by Jukka Aro on 13.3.2012.
#

import sys

def read_input(input_file, dim, is_float):
	f = open(input_file, 'r')
	M = [0]*dim*dim
	if is_float:
		for i in range (0,dim):
			line = f.readline()
			tokens  = line.split()
			for j in range(0,dim):
				M[i*dim+j] = float(tokens[j])
	else:
		for i in range (0,dim):
			line = f.readline()
			tokens  = line.split()
			for j in range(0,dim):
				M[i*dim+j] = int(float(tokens[j]))
	f.close()
	return M
	
def multiply_matrix(In, dim, is_float):
	Out = [0]*dim*dim
	
	for i in range (0,dim):
		for j in range (0,dim):
			res = 0
			for k in range (0,dim):
				res += In[i*dim+k]*In[k*dim+j]
			Out[i*dim+j] = res

#program entry:

if len(sys.argv) < 3 or len(sys.argv) > 5:
	print "Illegal numger of arguments"
	sys.exit()

input_file = sys.argv[1]
dim = int(sys.argv[2])
is_float = False
dry_run = False

if len(sys.argv) == 4:
	if sys.argv[3] == '--float':
		is_float = True
	elif sys.argv[3] == '--dry-run':
		dry_run = True
	else:
		print "Illegal argument: " + sys.argv[3]
		sys.exit()
if len(sys.argv) == 5:
	if sys.argv[3] == '--float' and sys.argv[4] == '--dry-run':
		is_float = True
		dry_run = True
	else:
		print "Illegal arguments: " + sys.argv[3] + " " + sys.argv[4]
		sys.exit()

if dry_run:
	read_input(input_file, dim, is_float)
else:
	multiply_matrix(read_input(input_file, dim, is_float), dim, is_float)
