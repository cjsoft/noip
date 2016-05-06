import java.lang.*;
import java.util.*;
import java.io.*;
class trie {
    class node {
        byte status;
        node []next = new node[10];
        node() {
            status = 0;
        }
    }
    int nne = 0;
    node []buffer;
    node root;
    trie() {
        buffer = new node[100007];
        for (int i = 0; i < 100007; i++) {
            buffer[i] = new node();
        }
        root = new node();
    }
    public boolean insert(String res) {
        int len = res.length();
        node cur = root;
        for (int i = 0; i < len; i++) {
            if (i == len - 1 && cur.next[(int)res.charAt(i) - 48] != null) {
                return false;
            }
            if (cur.next[(int)res.charAt(i) - 48] == null) {
                cur.next[(int)res.charAt(i) - 48] = buffer[nne];
                buffer[nne++].status = 0;
            }
            if (cur.next[(int)res.charAt(i) - 48].status != 0) {
                return false;
            }
            cur = cur.next[(int)res.charAt(i) - 48];
        }
        cur.status = 1;
        return true;
    }

}
class solution {
    public void solve(Scanner cin, PrintStream cout) {
        int t, t2;
        String temp;
        t = cin.nextInt();
        for (int i = 0; i < t; i++) {
            t2 = cin.nextInt();
            cin.nextLine();
            trie ts = new trie();
            boolean flag = true;
            for (int j = 0; j < t2; j++) {
                temp = cin.nextLine();
                if (!ts.insert(temp)) {
                    flag = false;
                }
            }
            if (!flag) {
                cout.println("NO");
            } else {
                cout.println("YES");
            }

        }
    }
}

public class p3630 {
    public static void main(String[] args) throws Exception {
        InputStream f = new FileInputStream("p3630.in");
        OutputStream ot = new FileOutputStream("p3630.out");
        Scanner cin = new Scanner(f);
        PrintStream ow = new PrintStream(ot);
        (new solution()).solve(cin, ow);
        cin.close();
        ot.close();
    }
}