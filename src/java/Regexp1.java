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
	void regexpMatch(String inputFile, boolean orOperator, boolean dryRun) {
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
				int count = 0;
				String regex = orOperator ? "\\d+|\\w+\\d+\\." : "\\d+";
				Pattern pattern = Pattern.compile(regex);
				while((currentLine = lineReader.readLine()) != null) {
					if(pattern.matcher(currentLine).find())
						count++;
				}
			}
			lineReader.close();
		} catch(IOException e) {
			System.err.println("Corrupted input file");
			System.exit(1);
		}
	}
	
    public static void main(String[] args) {
		boolean orOperator = false, dryRun = false;
		
		switch(args.length){
			case 1:
				break;
			case 2:
				if(args[1].compareTo("--with-or-operator") == 0)
					orOperator = true;
				else if(args[1].compareTo("--dry-run") == 0)
					dryRun = true;
				else {
					System.err.println("Illegal argument: "  + args[1]);
					System.exit(1);
				}
				break;
			case 3:
				if(args[1].compareTo("--with-or-operator") == 0 &&
				   args[2].compareTo("--dry-run") == 0) {
					orOperator = true;
					dryRun = true;
				}
				else {
					System.err.println("Illegal arguments: "  + args[1] + " " + args[2]);
					System.exit(1);
				}
				break;
			default:
				System.err.println("Illegal number of arguments");
				System.exit(1);
		}
		
		new Regexp1().regexpMatch(args[0], orOperator, dryRun);
    }
}
