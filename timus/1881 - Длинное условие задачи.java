import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        boolean oj = System.getProperty("ONLINE_JUDGE") != null;
        Reader reader = oj ? new InputStreamReader(System.in) : new FileReader("input.txt");
        Writer writer = oj ? new OutputStreamWriter(System.out) : new FileWriter("output.txt");
        StreamTokenizer in = new StreamTokenizer(new BufferedReader(reader));
        PrintWriter out = new PrintWriter(writer);

        BufferedReader br = new BufferedReader(reader);
        BufferedWriter bw = new BufferedWriter(writer);

        String line = br.readLine();

        Integer h = Integer.parseInt(line.split(" ")[0]);
        Integer w = Integer.parseInt(line.split(" ")[1]);
        Integer n = Integer.parseInt(line.split(" ")[2]);
        Integer counter = 1;


        int l = -1;
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            l = l + s.length() + 1;
            if (l > w) {
                counter++;
                l = s.length();
            }
        }

        Integer result = counter / h;
        result = (counter % h == 0) ? result : result + 1;

        bw.write(result.toString());
        bw.flush();
    }
}