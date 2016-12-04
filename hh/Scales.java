package com.example.scales;

import javafx.util.Pair;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by dubinets on 17.09.2014.
 */
public class Scales {

    final static String[] file = {
            "./data/scales-1.txt"
    };

    final static int TARGET_WEIGHT = 100;

    static boolean isWeight100 = false;

    public static int readFile(String fileName, ArrayList<Integer> sequence) throws FileNotFoundException, IOException {
        String line = null;
        BufferedReader reader = new BufferedReader(new FileReader(fileName));

        if((line = reader.readLine()) != null) {
            List<String> numberString = Arrays.asList(line.split(" "));
            for(String t : numberString) {
                sequence.add(Integer.parseInt(t));
            }
        }
        return 0;
    }

    public static int accumulate(ArrayList<Integer> v) {
        int n = 0; for(Integer s : v) n += s; return n;
    }

    public static ArrayList<Integer> balancedPartition(ArrayList<Integer> v) {
        int n = v.size();
        int sum = accumulate(v);
        int max_sum = sum / 2, diff = Integer.MAX_VALUE;

        ArrayList<Pair<Boolean, ArrayList<Integer>>> a = new ArrayList<Pair<Boolean, ArrayList<Integer>>>();

        a.add(new Pair<Boolean, ArrayList<Integer>>(true, null)); // 0
        for(int i = 1; i <= sum; i++) a.add(new Pair<Boolean, ArrayList<Integer>>(false, null));

        for(int i = 0; i < n; i++) {
            for(int j = sum; j >= 0; j--) {
                if(a.get(j).getKey()) {
                    ArrayList<Integer> array_loc;
                    if( a.get(j + v.get(i)).getValue() == null )
                        array_loc = new ArrayList<Integer>();
                    else
                        array_loc = new ArrayList<Integer>(a.get(j + v.get(i)).getValue());

                    array_loc.add(v.get(i));

                    if(accumulate(array_loc) > j + v.get(i))
                        continue;

                    if(a.get(j).getValue() != null)
                        array_loc.addAll(a.get(j).getValue());

                    a.set(j + v.get(i), new Pair<Boolean, ArrayList<Integer>>(true, array_loc));
                }
            }
        }

        // is can we get weight 100
        if(a.size() >= TARGET_WEIGHT)
            isWeight100 = a.get(100).getKey();

        for(int j = sum / 2; j >= 1; j--)
            if(a.get(j).getKey()) {
                ArrayList<Integer> loc = a.get(j).getValue();
                return loc;
            }

        //--------------------
//        boolean[] sub = new boolean[sum + 1];
//        sub[0] = true;
//        for(int i = 1; i <= sum; i++) sub[i] = false;
//
//        for(int i = 0; i < n; i++) {
//            for(int j = sum; j >= 0; j--) {
//                if(sub[j]) {
//                    sub[j + v.get(i)] = true;
//                }
//            }
//        }
//        for(int j = sum/2; j>=1; j--)
//            if(sub[j]) {
//                return Math.abs(sum - 2 * j);
//            }
        return null;
    }

    public static String printScales(ArrayList<Integer> allStones, ArrayList<Integer> subStones) {
        String s = new String("");

        ArrayList<Integer> right = subStones;
        ArrayList<Integer> left = new ArrayList<Integer>(allStones);

        left.removeAll(right);

//        if( accumulate(right) == accumulate(left) )
//            System.out.println("Scales can be balanced");
//        else
//            System.out.println("Scales can not be balanced");

        for(Integer v : left) {
            s += v.toString();
            s += " ";
        }

        s += "- ";

        for(Integer v : right) {
            s += v.toString();
            s += " ";
        }
        return s;
    }

    public static void main(String[] args) throws IOException {
        ArrayList<Integer> sequence = new ArrayList<Integer>();

        readFile(file[0], sequence);

        /*** Balance */
        System.out.println(printScales(sequence, balancedPartition(sequence)));
        System.out.println( (isWeight100) ? "yes" : "no" );
    }
}
