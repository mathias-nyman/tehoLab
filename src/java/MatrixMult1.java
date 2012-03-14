/*
 *  MatrixMult1.java
 *  
 *
 *  Created by Jukka Aro on 12.3.2012.
 *
 */
import java.io.*;
import java.util.Vector;

public class MatrixMult1 {

	private float[] readFloatMatrix(String inputFile, int dim) {
		FileReader fr = null;
		
		try {
			fr = new FileReader(inputFile);
		} catch(FileNotFoundException e) {
			System.err.println("Could not open file " + inputFile);
			System.exit(1);
		}
		
		BufferedReader lineReader = new BufferedReader(fr);
		
		float[] matrix = new float[dim*dim];
		String currentLine = null;
		
		try {
			for(int i = 0; i < dim; i++) {
				currentLine = lineReader.readLine();
				String[] tokens = currentLine.split(" ");
				
				for(int j = 0; j < dim; j++) {
					try {
						matrix[i*dim + j] = Float.parseFloat(tokens[j]);
					}
					catch(NumberFormatException e) {
						System.err.println("Corrupted input file");
						System.exit(1);
					}
				}
			}
			lineReader.close();
		} catch(IOException e) {
			System.err.println("Corrupted input file");
			System.exit(1);
		}
		
		return matrix;
	}
	
	private int[] readIntMatrix(String inputFile, int dim) {
		FileReader fr = null;
		
		try {
			fr = new FileReader(inputFile);
		} catch(FileNotFoundException e) {
			System.err.println("Could not open file " + inputFile);
			System.exit(1);
		}
		
		BufferedReader lineReader = new BufferedReader(fr);
		
		int[] matrix = new int[dim*dim];
		String currentLine = null;
		
		try {
			for(int i = 0; i < dim; i++) {
				currentLine = lineReader.readLine();
				String[] tokens = currentLine.split(" ");
				
				for(int j = 0; j < dim; j++) {
					try {
						matrix[i*dim+j] = new Float(tokens[j]).intValue();
					}
					catch(NumberFormatException e) {
						System.err.println("Corrupted input file");
						System.exit(1);
					}
				}
			}
			lineReader.close();
		} catch(IOException e) {
			System.err.println("Corrupted input file");
			System.exit(1);
		}
		
		return matrix;
	}
	
	private void multiplyFloatMatrix(float[] inMatrix, int dim) {
		
		float[] outMatrix = new float[dim*dim];
		
		for(int i = 0; i < dim; i++) {
			for(int j = 0; j < dim; j++) {
				float res = 0;
				for(int k = 0; k < dim; k++)
					res += inMatrix[dim*i+k]*inMatrix[k*dim+j];
				outMatrix[i*dim+j] = res;
			}
		}
	}
	
	private void multiplyIntMatrix(int[] inMatrix, int dim) {
		
		int[] outMatrix = new int[dim*dim];
		
		for(int i = 0; i < dim; i++) {
			for(int j = 0; j < dim; j++) {
				int res = 0;
				for(int k = 0; k < dim; k++)
					res += inMatrix[dim*i+k]*inMatrix[k*dim+j];
				outMatrix[i*dim+j] = res;
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
			MatrixMult1 mm = new MatrixMult1();
			mm.multiplyFloatMatrix(mm.readFloatMatrix(inputFile, dim), dim);
		}
		else {
			MatrixMult1 mm = new MatrixMult1();
			mm.multiplyIntMatrix(mm.readIntMatrix(inputFile, dim), dim);
		}
    }
}
