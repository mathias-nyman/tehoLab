import java.io.*;
import java.util.List;
import java.util.ArrayList;
import java.lang.StringBuilder;

class Concat2 {
    public static void main(String[] args) {
        List<String> lines = new ArrayList<String>();
        try {
          BufferedReader br= new BufferedReader(new FileReader(args[0]));
          String str;
          while ((str = br.readLine()) != null) {
              lines.add(str + '\n');
          }
          br.close();
        } catch (Exception e) { System.out.println(e); }

        if (args.length > 1 && args[1].equals("--dry-run")) {
            return;
        }

        StringBuilder strBuilder = new StringBuilder();
        for (int i=0; i < lines.size() ; i++)
            strBuilder.append(lines.get(i));

        String concatenated = strBuilder.toString();
    }
}
