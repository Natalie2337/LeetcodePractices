// 通过！！
// 反转链表
// 迭代法
// 初始化三个指针：prev、curr 和 next。prev 用于跟踪当前节点的前一个节点，初始化为 nullptr；curr 用于遍历链表，初始化为链表的头节点 head；next 用于临时存储 curr 的下一个节点，以便在改变 curr->next 指向后不丢失对下一个节点的引用。
// 遍历链表，直到 curr 为 nullptr：
// 将 next 设置为 curr->next，保存当前节点的下一个节点。
// 将 curr->next 改为 prev，即反转当前节点的指向。
// 更新 prev 和 curr，以便继续处理链表中的下一个节点。
// 最终，prev 会指向新的链表头部。
// 时间复杂度：O(n)，其中 n 是链表的长度。需要遍历链表一次。


 //Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * prev = nullptr;
        ListNode * curr = head;
        ListNode * next = nullptr;

        while(curr != nullptr){
            next = curr->next;
            curr->next = prev; // 先不管prev的初始化问题，这里实现了反转
            prev = curr; // 这两步实现向后移动一格
            curr = next; 
        }
        // prev初始化没有问题
        return prev; // 最后一次出来的时候，curr为nullptr, prev是它之前的一个，也就是新的head
    }
};