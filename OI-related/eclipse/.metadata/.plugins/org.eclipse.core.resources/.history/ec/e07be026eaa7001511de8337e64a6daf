import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class cf609b {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		(new solution(new Scanner(System.in), System.out)).solve();
	}

}

class solution {
	Scanner cin;
	PrintStream cout;
	solution(Scanner a, PrintStream b) {
		cin = a;
		cout = b;
	}
	public void solve() {
		long n;
		int m;
		long []a;
		n = cin.nextLong();
		m = cin.nextInt();
		a = new long[m + 1];
		Arrays.fill(a, 0);
		for (int i = 1; i <= n; i++) {
			a[cin.nextInt()]++;
		}
		long resu = (n - 1) * n / 2;
		for (long i : a) {
			if (i == 0) continue;
			resu -= i * (i - 1) / 2;
		}
		cout.println(resu);
	}
}