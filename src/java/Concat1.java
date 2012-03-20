/*
 *  Concat1.java
 *  
 *
 *  Created by Jukka Aro on 12.3.2012.
 *
 */
import java.io.*;

class Concat1 {
	
	void concatenate(String inputFile, boolean dryRun) {
		FileReader fr = null;
		
		try {
			fr = new FileReader(inputFile);
		} catch(FileNotFoundException e) {
			System.err.println("Could not open file " + inputFile);
			System.exit(1);
		}
		
		BufferedReader lineReader = new BufferedReader(fr);
		
		String currentLine = null;
		
		try {
			if(dryRun)
				while((currentLine = lineReader.readLine()) != null);
			else {
				StringBuffer result = new StringBuffer();
				while((currentLine = lineReader.readLine()) != null) {
					result.append(currentLine.trim());
				}
			}
			lineReader.close();
		} catch(IOException e) {
			System.err.println("Corrupted input file");
			System.exit(1);
		}
	}
	
    public static void main(String[] args) {
		boolean dryRun = false;
		
		switch(args.length){
			case 1:
				break;
			case 2:
				if(args[1].compareTo("--dry-run") == 0)
					dryRun = true;
				break;
			default:
				System.err.println("Illegal number of arguments");
				System.exit(1);
		}
		
		new Concat1().concatenate(args[0], dryRun);
    }
}
