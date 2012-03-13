import sys

class Matrix:
	def __init__(self, dim):
		self.dim = dim
		self.array = [0]*dim*dim
		
	def set(self, i, j, value):
		self.array[i*self.dim + j] = value
		
	def get(self, i, j):
		return self.array[i*self.dim + j]

def read_input(input_file, dim, is_float):
	f = open(input_file, 'r')
	M = Matrix(dim)
	for i in range (0,dim):
		line = f.readline()
		tokens  = line.split()
		for j in range(0,dim):
			if is_float:
				tmp = float(tokens[j])
			else:
				tmp = int(float(tokens[j]))
			M.set(i,j,tmp)
	f.close()
	return M
	
def multiply_matrix(In, dim):
	Out = Matrix(dim)
	
	for i in range (0,dim):
		for j in range (0,dim):
			res = 0
			for k in range (0,dim):
				res += In.get(i,k)*In.get(k,j)
			Out.set(i,j,res)

if len(sys.argv) < 3 or len(sys.argv) > 4:
	print "Illegal numger of arguments"
	sys.exit()

input_file = sys.argv[1]
dim = int(sys.argv[2])

if len(sys.argv) == 4:
	if sys.argv[3] == '--float':
		is_float = True
	else:
		print "Illegal argument: " + sys.argv[3]
		sys.exit()
else:
	is_float = False

multiply_matrix(read_input(input_file, dim, is_float), dim)
