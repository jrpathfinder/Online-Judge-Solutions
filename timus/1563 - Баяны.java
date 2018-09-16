import java.io.*;
import java.util.*;

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

        Set<String> shops = new HashSet<>();

        for(int i = 0; i < n; i++) {
            String shop = reader1.readLine();

            if(shops.contains(shop)) counter++;
            else shops.add(shop);
        }

        writer1.write(counter.toString());

        writer1.flush();
    }
}