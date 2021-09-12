class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}
// 自己写的solution，其实不用这么麻烦，第一种方法是stack，
// 第二种方法是只记录 size，然后建数组，数组从后往前，链表从前往后
class Solution {
    public int[] reversePrint(ListNode head) {
        ListNode cur = head;
        ListNode nxt = null;
        ListNode pre = null;
        int size = 0;
        while(cur!=null){
            nxt = cur.next;
            cur.next = pre;
            pre = cur;
            cur = nxt;
            size++;
        }
        int[] ans = new int[size];
        for(int i=0;i<size;++i) {
            ans[i] = pre.val;
            pre = pre.next;
        }
        return ans;
    }
}
