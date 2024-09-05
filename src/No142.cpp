// 通过！
#include <unordered_set>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 方法一：哈希表
// 一个非常直观的思路是：我们遍历链表中的每个节点，并将它记录下来；一旦遇到了此前遍历过的节点，就可以判定链表中存在环。借助哈希表可以很方便地实现。
// 使用unordered_set来模拟哈希表的功能，因为我们只要看是不是遇到了重复的节点
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> visited_node;
        ListNode * curr = head;
        while (curr != nullptr) {
            // unordered_set.count() 函数用于检查一个特定元素是否存在于 unordered_set 容器中。
            // 由于 unordered_set 不允许存储重复的元素，这个函数通常用来判断一个元素是否在容器中。
            // 如果元素存在，则该函数返回 1，否则返回 0。
            if(visited_node.count(curr)){
                return curr; // 出现重复的节点的那里就是一个环
            }
            visited_node.insert(curr);
            curr = curr->next;
        }
        return nullptr;
    }
};

// 方法二：快慢指针

class Solution2{
public:
    
}