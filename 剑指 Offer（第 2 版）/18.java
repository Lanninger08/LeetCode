class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        if(head.val==val) return head.next;
        ListNode cur = head.next;
        ListNode prev = head;
        while(cur!=null && cur.val!=val){
            cur = cur.next;
            prev = prev.next;
        }
        prev.next = cur.next;
        return head;
    }
}