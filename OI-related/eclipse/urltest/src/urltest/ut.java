package urltest;
import java.io.*;
import java.util.*;
import java.lang.*;
import java.net.*;

public class ut {
	static urllib ulb;
	public static void main(String[] args) {
		ulb = new urllib();
		File f = new File("D:\\a.html");
		try {
			FileWriter fout = new FileWriter(f);
			fout.write(ulb.get("http://www.baidu.com"));;
			fout.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}