import java.io.*;
import java.util.List;
import java.util.ArrayList;
import java.util.regex.*;

class Regexp2 {
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
        if (args.length > 2 && args[2].equals("--dry-run")) {
            return;
        }

        Pattern pattern = Pattern.compile("\\d+");
        if (args.length > 1 && args[1].equals("--with-or-operator")) {
            pattern = Pattern.compile("\\d+|\\w+\\d+\\.");
        }

        Matcher match;
        int amountFound = 0;
        for (int i=0; i < lines.size(); i++) {
            match = pattern.matcher(lines.get(i));
            if (match.find()) {
                amountFound++;
            }
        }

        //TODO: add cpu time measurement
    }
}
