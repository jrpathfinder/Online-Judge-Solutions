import java.io.*;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) throws IOException {
        boolean oj = System.getProperty("ONLINE_JUDGE") != null;
        Reader reader = oj ? new InputStreamReader(System.in) : new FileReader("input.txt");
        Writer writer = oj ? new OutputStreamWriter(System.out) : new FileWriter("output.txt");
        StreamTokenizer in = new StreamTokenizer(new BufferedReader(reader));
        PrintWriter out = new PrintWriter(writer);

        BufferedReader reader1 = new BufferedReader(reader);
        BufferedWriter writer1 = new BufferedWriter(writer);

        Integer n = Integer.parseInt(reader1.readLine());
        Integer counter = 0;

        ArrayList<String> guests = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            guests.add(reader1.readLine());
            counter++;
            if(guests.get(i).contains("+one")) counter++;
        }

        if (((counter + 2) == 13)) {
            writer1.write("1400");
        } else {
            writer1.write(new Integer ((counter + 2) * 100).toString());
        }
        writer1.flush();
        
    }
}
