import java.lang.*;
import java.util.*;
import java.io.*;

class rtn {
    int a, b;
    rtn() {
        a = b = 0;
    }
    void seta(int a_) {
        a = a_;
    }
    void setb(int b_) {
        b = b_;
    }
}

class solution {
    int p, e, i, d;
    int M;
    int mp, me, mi;
    int tp, te, ti;
    solution() {
        p = e = i = d = 0;
        M = 21252;
        mp = 28 * 33;
        me = 23 * 33;
        mi = 23 * 28;
        tp = te = ti = 0;
    }
    int exgcd(int a, int b, rtn aaa) {
        if (b == 0) {
            aaa.seta(1); aaa.setb(0);
            return a;
        }
        int temp = exgcd(b, a % b, aaa);
        int tx = aaa.a, ty =aaa.b;
        aaa.seta(ty);
        aaa.setb(tx - a / b * ty);
        return temp;
    }
    int mod_reverse(int a, int p) {
        rtn asd = new rtn();
        exgcd(a, p, asd);
        return (asd.a % p + p) % p;
    }
    void solve (Scanner cin) {
        int cnt = 1;
        int ap, ae, ai;
        do {
            int d;
            ap = cin.nextInt();
            ae = cin.nextInt();
            ai = cin.nextInt();
            d = cin.nextInt();
            if (ap == -1) break;
            tp = mod_reverse(mp, 23);
            te = mod_reverse(me, 28);
            ti = mod_reverse(mi, 33);
            int asd = 1;
            asd = ap * tp * mp + ae * te * me + ai * ti * mi;
            int res = asd % M - d;
            if (res <= 0) res += M;
            System.out.printf("Case %d: the next triple peak occurs in %d days.\n", cnt++, res);
        } while (ap != -1);
    }
}

public class p1006 {
    
    public static void main(String []args) throws Exception {
        Scanner cin = new Scanner(System.in);
        solution t = new solution();
        t.solve(cin);
    }

}