// 剑指 Offer 22. 链表中倒数第k个节点
// https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/

#include<stdio.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 双指针
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* slow = head;
        for(int i=0;i<k;++i){
            head = head->next;
        }
        while(head){
            head = head->next;
            slow = slow->next;
        }
        return slow;
    }
};