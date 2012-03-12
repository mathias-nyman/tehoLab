/*
 *  Concat1.java
 *  
 *
 *  Created by Jukka Aro on 12.3.2012.
 *
 */
import java.io.*;

class Concat1 {
	
	void concatenate(String inputFile) {
		FileReader fr = null;
		
		try {
			fr = new FileReader(inputFile);
		} catch(FileNotFoundException e) {
			System.err.println("Could not open file " + inputFile);
			System.exit(1);
		}
		
		BufferedReader lineReader = new BufferedReader(fr);
		
		String currentLine = null;
		StringBuffer result = new StringBuffer();
		
		try {
			while((currentLine = lineReader.readLine()) != null) {
				result.append(currentLine.trim());
			}
		} catch(IOException e) {
			System.err.println("Corrupted input file");
			System.exit(1);
		}
	}
	
    public static void main(String[] args) {
		if(args.length != 1) {
			System.err.println("Illegal number of arguments");
			System.exit(1);
		}
		
		new Concat1().concatenate(args[0]);
    }
}
