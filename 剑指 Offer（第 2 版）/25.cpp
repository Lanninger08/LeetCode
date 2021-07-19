// 剑指 Offer 25. 合并两个排序的链表
// https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // 伪头节点，循环合并
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head_pre = new ListNode(-1);
        ListNode* cur = head_pre;
        while(l1&&l2){
            if(l1->val<=l2->val){
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        if(l1){
            cur->next = l1;
        }else{
            cur->next = l2;
        }
        return head_pre->next;
    }

    // 写的更优雅一点
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0), *p = res;
        while(l1 && l2 ){
            l1->val < l2->val ? (p->next = l1,l1 = l1->next) : (p->next = l2, l2 = l2->next);
            p = p->next;              
        }
        p->next = l1 ? l1 : l2;
        return res->next;
    }

    // 递归
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};