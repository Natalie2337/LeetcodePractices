#include <iostream>
using namespace std;
//Definition for singly-linked list.
struct ListNode{
    int val;
    ListNode * next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode * next): val(x), next(next) {}
};

ssize_t list_size(auto p) {
    return (p == nullptr) ? 0 : (1 + list_size(p -> next)); 
}

#define WRITE(a) do { \
    *write = a; \
    write = &a -> next; \
    a = a -> next; \
} while(0) 

class Solution {
public:

    //用快慢指针来找到从中间划分的点
    ListNode * findPartition(ListNode * head){
        if (head == nullptr) abort(); 
        ListNode * fast = head;
        ListNode * slow = head;
        while (1) {
            if (auto n = fast -> next; n != nullptr) {
                if (auto nn = n -> next; nn != nullptr) {
                    slow = slow -> next; 
                    fast = nn; 
                    continue; 
                }
            } 
            break; 
        }
        return slow; 
        // while((fast != nullptr) && (fast->next!=nullptr)){
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }
        // return slow; 
    }

    ListNode * mergeSortImpl(ListNode *seg1head){
        if (seg1head == nullptr) abort(); 
        auto seg1end = findPartition(seg1head); 
        auto seg2head = seg1end -> next; 
        if (seg2head == nullptr) return seg1head; 
        seg1end -> next = nullptr; 
        seg1head = mergeSortImpl(seg1head); 
        seg2head = mergeSortImpl(seg2head); 
        auto seg = merge(seg1head, seg2head); 
        puts("?"); 
        return seg; 
        // ListNode * partition = findPartition(head);
        // cout << "partition: " << partition->val << endl;
        // ListNode * right_head = partition -> next;
        // ListNode * left_head = head;
        // cout << "right_head: " << right_head->val << endl;
        // cout << "left_head: " << left_head->val << endl;
        // partition -> next = nullptr;
        // mergeSort(left_head);
        // mergeSort(right_head);
        // ListNode * left = mergeSort(left_head);
        // ListNode * right = mergeSort(right_head);
        // ListNode * newHead = merge(left,right);
        // return newHead;    
    }  

    ListNode * merge(ListNode * left_head, ListNode * right_head) {
        ListNode *ans; 
        // 二级指针，用来统一两种 ListNode* 变量的写入
        ListNode **write = &ans;  
        ListNode *leftCurr = left_head;
        ListNode *rightCurr = right_head;
        while (1) {
            if (leftCurr == nullptr) {
                if (rightCurr == nullptr) {
                    break; 
                }
                WRITE(rightCurr); 
            } else if (rightCurr == nullptr) {
                WRITE(leftCurr); 
            } else {
                if (leftCurr->val <= rightCurr->val) {
                    WRITE(leftCurr); 
                } else {
                    WRITE(rightCurr); 
                }
            }
        }
        *write = nullptr; 
        return ans; 
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return head; 
        ListNode * rst =  mergeSortImpl(head);
        return rst;
    }
};

void dbg(auto p) {
    printf("%p", (void *)p); 
    if (p != nullptr) {
        printf(": %d; ", p -> val); 
        dbg(p -> next); 
    } else {
        puts(""); 
    }
}

int main(){
    ListNode * node = new ListNode(1);
    dbg(node); 
    node->next = new ListNode(3);
    node->next->next = new ListNode(4);
    // node->next->next->next = new ListNode(2);
    // node->next->next->next->next = new ListNode(6);
    // node->next->next->next->next->next = new ListNode(5);
    dbg(node); 
    // node->next->next->next->next->next->next = nullptr; 

    ListNode * temp = node;

    // for(int i=0; i<6; i++){
    //     cout << temp->val << " ";
    //     temp = temp->next;
    // }

    Solution sol;
    ListNode * ans = sol.mergeSortImpl(temp);
    //cout << head->val << endl;
    dbg(ans); 
}