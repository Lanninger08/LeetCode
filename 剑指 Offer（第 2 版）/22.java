public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode node1 = head;
        for(int i=0;i<k;i++){
            node1 = node1.next;
        }
        while(node1!=null){
            node1 = node1.next;
            head = head.next;
        }
        return head;
    }
}