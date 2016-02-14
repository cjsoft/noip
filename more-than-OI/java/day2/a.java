import java.util.*;
import java.lang.*;
import java.io.*;
public class a {
    static Scanner input;
    static PrintStream output;
    private static void initIO() {
        input = new Scanner(System.in);
        output = System.out;
    }
    public static void main (String []args) {
        initIO();
        output.println(Integer.parseInt("123"));
    }
}