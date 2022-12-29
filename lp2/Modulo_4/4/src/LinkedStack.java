import java.util.LinkedList;

public class LinkedStack implements IStackable{
	
	LinkedList<Integer> nums = new LinkedList<>();	
	
	@Override
	public int size() {
		return nums.size();
	}

	@Override
	public void push(int v) {
		nums.addFirst(v);
	}

	@Override
	public int pop() {
		return nums.removeFirst();
	}

}
