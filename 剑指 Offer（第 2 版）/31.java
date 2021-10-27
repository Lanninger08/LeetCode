class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stack = new Stack<>();
        int poppedIndex = 0;
        int pushedIndex = 0;
        for(int i=0;i<pushed.length;i++){
            stack.push(pushed[i]);
            while(!stack.empty()&&popped[poppedIndex]==stack.peek()){
                poppedIndex++;
                stack.pop();
            }
        }
        return stack.empty();
    }
}