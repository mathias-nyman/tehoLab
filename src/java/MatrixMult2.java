import java.io.*;
import java.util.List;
import java.util.ArrayList;

class MatrixMult2 {
    static <T> void matrixMult(T[][] result, T[][] matrix) {
        for (int i=0; i < matrix.length; ++i) {
            for (int j=0; j < matrix.length; ++j) {
                for (int k=0; k < matrix.length; ++k) {
                    result[i][j] += matrix[i][k] * matrix[k][j];
                }
            }
        }
    }

    public static void main(String[] args) {
        int[][] intMatrix = new int[0][0];
        float[][] floatMatrix = new float[0][0];
        int dimension = 0;
        boolean isFloat = false;

        try {
            BufferedReader br= new BufferedReader(new FileReader(args[0]));
            dimension = Integer.parseInt(args[1]);

            if (args.length > 2 && args[2].equals("--float")) {
                isFloat = true;
            }

            intMatrix = new int[dimension][dimension];
            floatMatrix = new float[dimension][dimension];

            String line;
            while ((line = br.readLine()) != null) {
                String[] strArray = line.split("\\s+");
                for (int i=0; i < strArray.length; ++i) {
                    if (isFloat)
                        floatMatrix[0][i] = Float.parseFloat(strArray[i]);
                    else
                        intMatrix[0][i] = Integer.parseInt(strArray[i]);
                }
            }
            br.close();
        } catch (Exception e) { System.out.println(e); }

        int[][] intResult = new int[dimension][dimension];
        float[][] floatResult = new float[dimension][dimension];
        if (isFloat)
            matrixMult(floatResult, floatMatrix);
        else
            matrixMult(intResult, intMatrix);

        //TODO: add cpu time measurement
    }
}
