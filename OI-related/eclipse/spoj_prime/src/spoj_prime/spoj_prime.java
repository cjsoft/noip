package spoj_prime;
import java.lang.*;
import java.lang.reflect.Array;
import java.io.*;
import java.util.*;
class solution {
	ArrayList<Integer> prime;
	Boolean []isprime;
	solution(){}
	ArrayList<Integer> generate(int upper) {
		prime = new ArrayList<Integer>();
		isprime = new Boolean[upper + 17];
		Arrays.fill(isprime, true);
		isprime[0] = false;
		isprime[1] = false;
		for (int i = 2; i <= upper; i++) {
			if (isprime[i]) {
				prime.add(i);
			}
			for (Integer j : prime) {
				if (i * j > upper) {
					break;
				}
				isprime[i * j] = false;
				if (j % i == 0) {
					break;
				}
			}
		}
		return prime;
	}
}
public class spoj_prime {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int t = cin.nextInt();
		solution so = new solution();
		for (int i = 0; i < t; i++) {
			int n, m;
			m = cin.nextInt();
			n = cin.nextInt();
			ArrayList<Integer> resu = so.generate(n);
			for (Integer j : resu) {
				if (j >= m) {
					System.out.println(j);
				}
			}
			System.out.println();
		}
		cin.close();
	}

}
