// 剑指 Offer 24. 反转链表
// https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/

#include<stdio.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // iter
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur){
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    // recursion
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};