/*
 *  Regexp1.java
 *  
 *
 *  Created by Jukka Aro on 14.3.2012.
 *
 */
import java.io.*;
import java.util.regex.*;

class Regexp1 {
	void regexpMatch(String inputFile, boolean orOperator) {
		FileReader fr = null;
		
		try {
			fr = new FileReader(inputFile);
		} catch(FileNotFoundException e) {
			System.err.println("Could not open file " + inputFile);
			System.exit(1);
		}
		
		BufferedReader lineReader = new BufferedReader(fr);
		
		String regex = orOperator ? "\\d+|\\w+\\d+\\." : "\\d+";
		Pattern pattern = Pattern.compile(regex);
		
		String currentLine = null;
		int count = 0;
		
		try {
			while((currentLine = lineReader.readLine()) != null) {
				if(pattern.matcher(currentLine).find())
					count++;
			}
			lineReader.close();
		} catch(IOException e) {
			System.err.println("Corrupted input file");
			System.exit(1);
		}
		System.out.println(count);
	}
	
    public static void main(String[] args) {
		if(args.length > 2) {
			System.err.println("Illegal number of arguments");
			System.exit(1);
		}
		
		boolean orOperator = (args.length == 2 && args[1].compareTo("--with-or-operator") == 0) ?
		true : false;
		
		new Regexp1().regexpMatch(args[0], orOperator);
    }
}
