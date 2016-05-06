import java.io.*;
import java.util.*;
import java.lang.*;


public class helloworld {
    public static void main(String []args) {
        System.out.println(String.format("%d:%d", 1, 2));
        Integer []a = new Integer[10];
        Arrays.fill(a, 0);
        a[0] = 0;
        a[1] = 1;
        a[2] = 2;
        a[3] = 3;
        a[4] = 4;
        a[5] = 5;
        a[6] = 6;
        a[7] = 7;
        Arrays.sort(a, new RCMP());
        for (Integer i : a) {
            System.out.println(i);
        }
    }
}

class RCMP implements Comparator<Integer> {
    public int compare(Integer a_, Integer b_) {
        try {
            int a = a_.intValue();
            int b = b_.intValue();
            if (a > b) {
                return 1;
            } else if (a < b) {
                return -1;
            } else {
                return 0;
            }
        } catch(Exception e) {
            return 0;
        }
    }
}