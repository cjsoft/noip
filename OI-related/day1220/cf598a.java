import java.lang.*;
import java.util.*;
import java.io.*;

public class cf598a {
    public static void main(String []args) throws Exception {
        Scanner i = new Scanner(System.in);
        (new solution()).solve(i, System.out);
    }
}
class solution {
    int tc;
    ArrayList<Long> al;
    solution() {
        tc = 0;
        al = new ArrayList<Long>();
        Long tp = new Long(1);
        for (int i = 0; i < 32; i++) {
            al.add(tp);
            tp <<= 1;
        }
    }
    public void solve(Scanner cin, PrintStream cout) {
        tc = cin.nextInt();
        Long temp, resu;
        for (int i = 0; i < tc; i++) {
            temp = cin.nextLong();
            resu = (1 + temp) * temp / 2;
            for (Long j : al) {
                if (j <= temp) {
                    resu -= j << 1;
                }
            }
            cout.println(resu);
        }
    }
}
