package spoj_wtf_test;
import java.util.*;
import java.lang.*;
public class spoj_wtf_test {
	public static void main(String []args) throws Exception{
		Scanner cin = new Scanner(System.in);
		int temp;
		temp = cin.nextInt();
		while (temp != 42) {
			System.out.println(temp);
			temp = cin.nextInt();
		}
		cin.close();
	}
}