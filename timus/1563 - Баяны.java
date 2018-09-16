import javafx.util.Pair;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {
        boolean oj = true;
        Reader reader = oj ? new InputStreamReader(System.in) : new FileReader("input.txt");
        Writer writer = oj ? new OutputStreamWriter(System.out) : new FileWriter("output.txt");
        StreamTokenizer in = new StreamTokenizer(new BufferedReader(reader));
        PrintWriter out = new PrintWriter(writer);

        BufferedReader br = new BufferedReader(reader);
        BufferedWriter bw = new BufferedWriter(writer);

        Integer n = Integer.parseInt(br.readLine());
        String[] line = br.readLine().split(" ");

        List<Pair<Integer,Integer>> clients = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            Pair<Integer,Integer> client = new Pair<>(
                    i + 1,
                    Integer.parseInt(line[i])
            );
            clients.add(client);
        }

        Collections.sort(clients, Comparator.comparingInt(Pair::getValue));

        for(int i = 0; i < n; i++) {
            bw.write(clients.get(i).getKey().toString());
            bw.write(" ");
            if(i != 0 && i % 2 == 1) bw.newLine();
        }

        bw.flush();

    }
}
