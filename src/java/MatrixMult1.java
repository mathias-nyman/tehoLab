/*
 *  MatrixMult1.java
 *  
 *
 *  Created by Jukka Aro on 12.3.2012.
 *
 */
import java.io.*;
import java.util.Vector;

public class MatrixMult1<T> {
	
	public class Matrix<T> {
		private int dim;
		private Vector<T> vector;
		
		public Matrix(int dimension) {
			dim = dimension;
			vector = new Vector<T>();
			vector.ensureCapacity(dim);
		}
		
		public void setAt(int row, int col, T val) {
			vector.add(row*dim + col, val);
		}
		
		public T getAt(int row, int col) {
			return vector.get(row*dim + col);
		}
	}
	

	private Matrix<Float> readFloatMatrix(String inputFile, int dim) {
		FileReader fr = null;
		
		try {
			fr = new FileReader(inputFile);
		} catch(FileNotFoundException e) {
			System.err.println("Could not open file " + inputFile);
			System.exit(1);
		}
		
		BufferedReader lineReader = new BufferedReader(fr);
		
		Matrix<Float> matrix = new Matrix<Float>(dim);
		String currentLine = null;
		
		for(int i = 0; i < dim; i++) {
			try {
				if((currentLine = lineReader.readLine()) == null) {
					System.err.println("Corrupted input file");
					System.exit(1);
				}
			} catch(IOException e) {
				System.err.println("Corrupted input file");
				System.exit(1);
			}
			
			String[] tokens = currentLine.split(" ");

			if(tokens.length < dim) {
				System.err.println("Corrupted input file");
				System.exit(1);
			}
			
			for(int j = 0; j < dim; j++) {
				try {
					matrix.setAt(i, j, new Float(tokens[j]));
				}
				catch(NumberFormatException e) {
					System.err.println("Corrupted input file");
					System.exit(1);
				}
			}
		}
		
		return matrix;
	}
	
	private Matrix<Integer> readIntMatrix(String inputFile, int dim) {
		FileReader fr = null;
		
		try {
			fr = new FileReader(inputFile);
		} catch(FileNotFoundException e) {
			System.err.println("Could not open file " + inputFile);
			System.exit(1);
		}
		
		BufferedReader lineReader = new BufferedReader(fr);
		
		Matrix<Integer> matrix = new Matrix<Integer>(dim);
		String currentLine = null;
		
		for(int i = 0; i < dim; i++) {
			try {
				if((currentLine = lineReader.readLine()) == null) {
					System.err.println("Corrupted input file");
					System.exit(1);
				}
			} catch(IOException e) {
				System.err.println("Corrupted input file");
				System.exit(1);
			}
			String[] tokens = currentLine.split(" ");
			
			if(tokens.length < dim) {
				System.err.println("Corrupted input file");
				System.exit(1);
			}
			
			for(int j = 0; j < dim; j++) {
				try {
					matrix.setAt(i, j, new Integer(new Float(tokens[j]).intValue()));
				}
				catch(NumberFormatException e) {
					System.err.println("Corrupted input file");
					System.exit(1);
				}
			}
		}
		
		return matrix;
	}
	
	private void multiplyFloatMatrix(Matrix<Float> inMatrix, int dim) {
		
		Matrix<Float> outMatrix = new Matrix<Float>(dim);
		
		for(int i = 0; i < dim; i++) {
			for(int j = 0; j < dim; j++) {
				float res = 0;
				for(int k = 0; k < dim; k++)
					res += inMatrix.getAt(i, k).floatValue()*inMatrix.getAt(k, j).floatValue();
				outMatrix.setAt(i, j, res);
			}
		}
	}
	
	private void multiplyIntMatrix(Matrix<Integer> inMatrix, int dim) {
		
		Matrix<Integer> outMatrix = new Matrix<Integer>(dim);
		
		for(int i = 0; i < dim; i++) {
			for(int j = 0; j < dim; j++) {
				int res = 0;
				for(int k = 0; k < dim; k++)
					res += inMatrix.getAt(i, k).intValue()*inMatrix.getAt(k, j).intValue();
				outMatrix.setAt(i, j, res);
			}
		}
	}
	
    public static void main(String[] args) {
		if(args.length < 2 || args.length > 3) {
			System.err.println("Illegal number of arguments");
			System.exit(1);
		}
		
		String inputFile = args[0];
		int dim = 0;
		
		try {
			dim = Integer.parseInt(args[1]);
			if(dim <= 0) {
				System.err.println("Illegal dimension: " + args[1]);
				System.exit(1);
			}
		}
		catch(NumberFormatException e) {
			System.err.println("Illegal argument: " + args[1]);
			System.exit(1);
		}
		
		if(args.length == 3 && args[2].compareTo("--float") == 0) {
			MatrixMult1<Float> mm = new MatrixMult1<Float>();
			mm.multiplyFloatMatrix(mm.readFloatMatrix(inputFile, dim), dim);
		}
		else {
			MatrixMult1<Integer> mm  = new MatrixMult1<Integer>();
			mm.multiplyIntMatrix(mm.readIntMatrix(inputFile, dim), dim);
		}
    }
}
