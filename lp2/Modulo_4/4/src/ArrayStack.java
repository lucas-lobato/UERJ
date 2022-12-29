import java.util.ArrayList;

public class ArrayStack implements IStackable{

	ArrayList<Integer> nums = new ArrayList<>();
	
	@Override
	public int size() {
		return nums.size();
	}

	@Override
	public void push(int v) {
		nums.add(v);
	}

	@Override
	public int pop() {
		return nums.remove(nums.size() - 1);
	}

}
