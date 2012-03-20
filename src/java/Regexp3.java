import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.CharBuffer;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Regexp3
{
	/**
	 * container/parser for arguments 
	 */
	public static class Configuration
	{
		public final File file;
		public final boolean dryRun;
		public final boolean withOrOperator;
		
		public Configuration(String[] args)
		{
			if(args.length < 1 || args[0].length() == 0)
			{
				throw new IllegalArgumentException("File name must be provided in the first argument");
			}
			
			file = new File(args[0]);
			
			boolean dryRun = false;
			boolean withOrOperator = false;
			
			for(int i = 1; i < args.length; i++)
			{
				if("--dry-run".equals(args[i]))
				{
					if(dryRun)
					{
						throw new IllegalArgumentException("Argument \"--dry-run\" provided multiple times.");
					}
					else
					{
						dryRun = true;
					}
				}
				else if("--with-or-operator".equals(args[i]))
				{
					if(withOrOperator)
					{
						throw new IllegalArgumentException("Argument \"--with-or-operator\" provided multiple times.");
					}
					else
					{
						withOrOperator = true;
					}
				}
				else
				{
					throw new IllegalArgumentException("Unknown argument: \"" + args[i] + "\".");
				}
			}
			
			this.dryRun = dryRun;
			this.withOrOperator = withOrOperator;
		}
	}
	
	/**
	 * 
	 * @return A list of CharSequences, each actually pointing to the same
	 *         master CharBuffer, thus keeping the buffer together in a single
	 *         point in memory.
	 * @throws IOException
	 */
	private static List<CharSequence> getLines(File file) throws IOException
	{
		// number of characters <= number of bytes
		CharBuffer charBuffer = CharBuffer.allocate((int)file.length());
		
		List<CharSequence> lines = new ArrayList<CharSequence>();
		
		Charset us_ascii = Charset.forName("US-ASCII");
		
		// read file entirely into memory
		BufferedReader bufferedReader = null;
		try
		{
			bufferedReader = new BufferedReader(new InputStreamReader(new FileInputStream(file), us_ascii));
			
			String line;
			while((line = bufferedReader.readLine()) != null)
			{
				// put line to common buffer
				charBuffer.mark();
				charBuffer.put(line);
				
				// create a 'view' of the line in buffer
				CharBuffer portion = charBuffer.duplicate();
				portion.limit(portion.position()).reset();
				portion = portion.slice();
				
				// put buffer to line list
				lines.add(portion);
			}
		}
		finally
		{
			// cleanup
			if(bufferedReader != null)
			{
				bufferedReader.close();
				bufferedReader = null;
			}
		}
		
		return lines;
	}
	
	public static void main(String[] args) throws IOException
	{
		// get configuration
		Configuration configuration = new Configuration(args);
		
		// get lines
		List<CharSequence> lines = getLines(configuration.file);
		
		if(!configuration.dryRun)
		{
			// run test
			
			String patternString;
			if(configuration.withOrOperator)
			{
				patternString = "\\d+|\\w+\\d+\\.";
			}
			else
			{
				patternString = "\\d+";
			}
			
			Pattern pattern = Pattern.compile(patternString);
			
			@SuppressWarnings("unused")
			int countMatches = 0;
			for(CharSequence line: lines)
			{
				Matcher matcher = pattern.matcher(line);
				
				if(matcher.find())
				{
					countMatches++;
				}
			}
			
			//System.out.println(countMatches);
		}
	}
}
