

public class App {

	public static void main(String[] args) {
		IStackable s1 = new LinkedStack();
		s1.push(10);
		s1.push(20);
		int v1 = s1.pop();
		int sz1 = s1.size();
		System.out.format("v=%d, sz=%d\n", v1, sz1);
		
		IStackable s2 = new ArrayStack();
		s2.push(10);
		s2.push(20);
		int v2 = s2.pop();
		int sz2 = s2.size();
		System.out.format("v=%d, sz=%d\n", v2, sz2);
	}
	
}
