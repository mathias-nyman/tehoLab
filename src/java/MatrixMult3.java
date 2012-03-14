import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.Charset;

class MatrixMult3
{
	/**
	 * container/parser for arguments 
	 */
	public static class Configuration
	{
		public final File file;
		public final int dimension;
		public final boolean dryRun;
		public final boolean asFloat;
		
		public Configuration(String[] args)
		{
			if(args.length < 2 || args[0].length() == 0 || args[1].length() == 0)
			{
				throw new IllegalArgumentException("File name must be provided in the first argument, and dimension in the second");
			}
			
			file = new File(args[0]);
			dimension = Integer.parseInt(args[1]);
			
			boolean dryRun = false;
			boolean asFloat = false;
			
			for(int i = 2; i < args.length; i++)
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
				else if("--float".equals(args[i]))
				{
					if(asFloat)
					{
						throw new IllegalArgumentException("Argument \"--float\" provided multiple times.");
					}
					else
					{
						asFloat = true;
					}
				}
				else
				{
					throw new IllegalArgumentException("Unknown argument: \"" + args[i] + "\".");
				}
			}
			
			this.dryRun = dryRun;
			this.asFloat = asFloat;
		}
	}
	
	public static class NumberSource
	{
		private final BufferedReader bufferedReader;
		
		boolean isEmpty;
		
		public NumberSource(File file) throws IOException
		{
			isEmpty = false;
			
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
			
			bufferedReader = new BufferedReader(new InputStreamReader(new FileInputStream(file), us_ascii));
			seekToNonWhite();
		}
		
		private void seekToNonWhite() throws IOException
		{
			int value;
			while(true)
			{
				bufferedReader.mark(1);
				value = bufferedReader.read();
				
				if(value < 0)
				{
					isEmpty = true;
					return;
				}
				else if(!Character.isWhitespace((char)value))
				{
					bufferedReader.reset();
					return;
				}
			}
		}
		
		public int getNumber() throws IOException
		{
			if(isEmpty)
			{
				throw new IllegalArgumentException("Provided input file is too short.");
			}
			
			int value;
			StringBuilder stringBuilder = new StringBuilder();
			while(true)
			{
				bufferedReader.mark(1);
				value = bufferedReader.read();
				
				if(value < 0)
				{
					isEmpty = true;
					break;
				}
				else if(Character.isWhitespace((char)value))
				{
					seekToNonWhite();
					break;
				}
				else
				{
					stringBuilder.append((char)value);
				}
			}
			
			return Integer.parseInt(stringBuilder.toString().split("\\.")[0]);
		}
		
		public void close() throws IOException
		{
			bufferedReader.close();
		}
	}
	
	public static class Matrix
	{
		private final int[][] data;
		
		public Matrix(int dimension)
		{
			data = new int[dimension][dimension];
		}
		
		public Matrix(int dimension, NumberSource numberSource) throws IOException
		{
			this(dimension);
			
			for(int row_index = 0; row_index < getDimension(); row_index++)
			{
				for(int cell_index = 0; cell_index < getDimension(); cell_index++)
				{
					data[row_index][cell_index] = numberSource.getNumber();
				}
			}
		}
		
		public int getDimension()
		{
			return data.length;
		}
		
		public static Matrix multiply(Matrix a, Matrix b)
		{
			if(a.getDimension() != b.getDimension())
			{
				throw new IllegalArgumentException("Matrices must be of the same dimension");
			}
			
			Matrix ret = new Matrix(a.getDimension());
			
			for(int row_index = 0; row_index < ret.getDimension(); row_index++)
			{
				for(int cell_index = 0; cell_index < ret.getDimension(); cell_index++)
				{
					for(int k = 0; k < ret.getDimension(); k++)
					{
						ret.data[row_index][cell_index] += a.data[row_index][k] * b.data[k][cell_index];
					}
				}
			}
			
			return ret;
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		// get configuration
		Configuration configuration = new Configuration(args);
		
		NumberSource numberSource = null;
		Matrix a;
		try
		{
			// get number source
			numberSource = new NumberSource(configuration.file);
			
			a = new Matrix(configuration.dimension, numberSource);
		}
		finally
		{
			if(numberSource != null)
			{
				numberSource.close();
				numberSource = null;
			}
		}
		
		if(!configuration.dryRun)
		{
			@SuppressWarnings("unused")
			Matrix c = Matrix.multiply(a, a);
		}
	}
}
