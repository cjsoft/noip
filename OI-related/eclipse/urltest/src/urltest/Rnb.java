package urltest;
import java.lang.*;
import java.io.*;
import java.util.*;
public abstract class Rnb implements Runnable {
	private Object attributes;
	public abstract void Run();
	public void setAttributes(Object a) {
		this.attributes = a;
	}
	public Object getAttributes() {
		return this.attributes; 
	}
}
