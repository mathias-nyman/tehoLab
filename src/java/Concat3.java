import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.CharBuffer;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.List;

public class Concat3
{
	/**
	 * container/parser for arguments 
	 */
	public static class Configuration
	{
		public final File file;
		public final boolean dryRun;
		
		public Configuration(String[] args)
		{
			if(args.length < 1 || args[0].length() == 0)
			{
				throw new IllegalArgumentException("File name must be provided in the first argument");
			}
			
			file = new File(args[0]);
			
			boolean dryRun = false;
			
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
				else
				{
					throw new IllegalArgumentException("Unknown argument: \"" + args[i] + "\".");
				}
			}
			
			this.dryRun = dryRun;
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
		
		/*
		 * IRC:
		 * 22:28 -´@: btw. mikä on stringitesteissä syötteen koodaus? UTF8?
		 * 22:28 -´@: voi olla yksinkertaisinta pysytellä ASCII osassa
		 * 22:28 -´@: sit ei tarvii ottaa kantaa
		 * 23:00  tiitu~__> snoukkis: samaa mieltä
		 */
		Charset us_ascii = Charset.forName("US-ASCII");
		/*
		 * other possibilities...
		 * 
		 * Charset iso_8859_1 = Charset.forName("ISO-8859-1");
		 * Charset iso_8859_15 = Charset.forName("ISO-8859-15");
		 * Charset utf_8 = Charset.forName("UTF-8");
		*/
		
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
				charBuffer.put(line + '\n');
				
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
			
			// is it allowed to 'know' the input length beforehand? Assuming not...
			StringBuilder stringBuilder = new StringBuilder(/*(int)configuration.file.length()*/);
			
			for(CharSequence line: lines)
			{
				stringBuilder.append(line);
			}
			
			//System.out.println(stringBuilder);
		}
	}
}
