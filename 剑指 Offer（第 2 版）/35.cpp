// 剑指 Offer 35. 复杂链表的复制
// https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/

#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    // 方法一：哈希表  
    // 时间复杂度O(n) 两轮遍历链表
    // 空间复杂度O(n) 哈希表
    Node* copyRandomList1(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*, Node*> map;
        Node* cur = head;
        // 复制并新建每个节点 
        while(cur){
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        // 构建新链表的指向
        cur = head;
        while(cur){
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        return map[head];
    }

    // 方法二：拼接 + 拆分
    /* 算法流程
       1. 复制各节点，构建拼接链表: node1->node2  node1->node1 new->node2->node2 new->..
       2. 构建新链表的random指向 cur->next->random = cur->random->next
       3. 拆分原 / 新链表: pre/cur node->next=node->next->next
    */
   Node* copyRandomList2(Node* head) {
        if(!head) return nullptr;
        Node* cur = head;
        // 复制
        while(cur){
            Node* tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
        // random指向
        cur = head;
        while(cur){
            if(cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        // 拆分
        Node* pre = head;
        Node* ans = head->next;
        cur = head->next;
        while(cur->next){
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = nullptr;
        return ans;
    }

};