import java.lang.*;
import java.lang.reflect.Array;
import java.io.*;
import java.util.*;
public class cf609a {

	public static void main(String[] args) {
		(new solution(new Scanner(System.in), System.out)).solve();

	}

}

class solution {
	Scanner cin;
	PrintStream cout;
	solution(Scanner i, PrintStream o) {
		cin = i;
		cout = o;
	}
	
	public void solve() {
		int n = cin.nextInt();
		int m = cin.nextInt();
		int []a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = cin.nextInt();
		}
		Arrays.sort(a);
		int cnt = 0;
		while (m > 0) {
			m -= a[n - 1 - cnt++];
		}
		cout.println(cnt);
		
	}
}

