import java.util.LinkedList;

class CQueue {
    LinkedList<Integer> stack1;
    LinkedList<Integer> stack2;
    public CQueue() {
        stack1 = new LinkedList<>();
        stack2 = new LinkedList<>();
    }
    
    public void appendTail(int value) {
        stack1.add(value);
    }
    
    public int deleteHead() {
        if(stack2.isEmpty()){
            while(!stack1.isEmpty()){
                stack2.add(stack1.removeLast());
            }
        }
        if(stack2.isEmpty()){
            return -1;
        }
        int ans = stack2.removeLast();
        return ans;
    }
}