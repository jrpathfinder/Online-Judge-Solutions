package com.example.median;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by dubinets on 16.09.2014.
 */

public class Median {

    final static String[] file = {
            "./data/1.txt"
    };

    public static int readFile(String fileName, ArrayList<ArrayList<Integer>> list_of_sequences) throws FileNotFoundException, IOException {
        String line = null;
        BufferedReader reader = new BufferedReader(new FileReader(fileName));

        for(int i = 0; (line = reader.readLine()) != null; i++) {
            List<String> numberString = Arrays.asList(line.split(" "));
            ArrayList<Integer> sequence = new ArrayList<Integer>();
            for(String t : numberString) {
                sequence.add(Integer.parseInt(t));
            }
            list_of_sequences.add(sequence);
        }
        return 0;
    }

    public static ArrayList<Integer> merge(ArrayList<ArrayList<Integer>> sequences) {
        for(int k = 0; k < sequences.size() - 1; k++) {
            for (int i = 0, j = 0; j < sequences.get(k+1).size(); i++) {
                if (i == sequences.get(k).size() || sequences.get(k).get(i) > sequences.get(k+1).get(j)) {
                    sequences.get(k).add(i, sequences.get(k+1).get(j++));
                }
            }
            sequences.get(k+1).clear();
        }
        return sequences.get(0);
    }

    public static void main(String[] args) throws IOException {
        ArrayList<ArrayList<Integer>> sequences = new ArrayList<ArrayList<Integer>>();

        readFile(file[0], sequences);

        ArrayList<Integer> a = sequences.get(0);
        ArrayList<Integer> b = sequences.get(1);
        int N = sequences.get(0).size();

        int left_a = 0; int right_a = N;
        int left_b = 0; int right_b = N;
        int middle_a = 0;
        int middle_b = 0;

        while (right_a - left_a != 1) {
            middle_a = (right_a + left_a - 1) / 2;
            middle_b = (right_b + left_b - 1) / 2;

            if(a.get(middle_a) >= b.get(middle_b)) {
                right_a = middle_a + 1;
                left_b = middle_b + (right_b - left_b + 1) % 2;
            }
            else {
                right_b = middle_b + 1;
                left_a = middle_a + (right_a - left_a + 1) % 2;
            }
        }

        // if (N = 2m + 1)
        //double median = (a.get(left_a) < b.get(left_b)) ? a.get(left_a) : b.get(left_b);

        // if (N = 2m + 2)
        double median = (a.get(left_a) + b.get(left_b)) / 2.0;
        System.out.println("Median of sequences is " + median);
    }
}
