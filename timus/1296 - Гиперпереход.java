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

        Integer n = Integer.parseInt(br.readLine());
        int[] p = new int[n];

        for(int i = 0; i < n; i++) {
            p[i] = Integer.parseInt(br.readLine());
        }

        Integer max_ending_here = 0;
        Integer max_so_far = Integer.MIN_VALUE;

        for(int i = 0; i < p.length; i++) {
            max_ending_here = max_ending_here + p[i];
            if(max_ending_here < 0)
                max_ending_here = 0;
            else if(max_so_far < max_ending_here)
                max_so_far = max_ending_here;
        }

        max_so_far = (max_so_far < 0) ? 0 : max_so_far;


        bw.write(max_so_far.toString());
        bw.flush();
    }
}