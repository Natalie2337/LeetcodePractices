// 通过！
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// 找到数组中的第k个最大的元素
// 构建一个容量为k的小顶堆，在循环中，我们不断地向堆中添加元素。
// 当堆的大小超过k时，我们移除堆顶元素（即最小的元素）。
// 这样做保证了堆中始终只有k个元素，这些元素是目前看过的前k大的元素。
// 这样堆顶的元素就刚好是第k个最大的元素（下面的元素都比它大）。


// 小顶堆
// 需要维护的变量：
// 数组：用于存储堆中的元素。我们使用一个一维数组来表示堆，其中对于任何位置i上的元素，其左孩子位于2*i + 1，右孩子位于2*i + 2，父节点位于(i-1)/2。
// 容量：堆可以存储的最大元素数量，这决定了数组的大小。
// 当前大小：堆中当前元素的数量，这有助于我们知道下一个插入的元素应该放在哪个位置，以及何时认为堆已满。
class MinHeap{
private:
    int * heap; // 指向动态分配的整型数组的指针,相当于维护了一个数组
    // 具有灵活性，在运行时确定数组的大小，而不是在编译时。这意味着我们可以根据程序的需求（例如，堆的容量）来分配恰好所需的内存量。
    int capacity; // 堆的最大容量
    int size; // 当前堆中已有的元素个数

public:
    MinHeap(int cap) : capacity(cap), size(0) {
        heap = new int[cap];
    }
    ~MinHeap(){
        delete[] heap; // 释放动态分配的数组
    }

    //插入操作
// 当向堆中插入新元素时，我们遵循以下步骤：
// 将新元素添加到堆的末尾（即数组的最后一个未使用的位置）。
// 从新元素开始，与其父节点比较。如果新元素小于其父节点，则交换它们的位置。
// 重复上一步，直到新元素的父节点不再大于它，或者它成为新的堆顶。
// 这个过程称为“上浮”（upheap 或 percolate up）。
    void insert(int element){
        if(size < capacity){
            heap[size] = element;
            int i = size; //上浮！
            // 那么它的父节点应该是(i-1)/2 (不管是左子节点还是右子节点都成立，详见笔记！)
            while(i!=0){
                // 直至它成为新的堆顶(i=0)
                if(heap[i] >= heap[(i-1)/2] ){
                    break; // 如果父节点不再大于它
                }

                // 元素小于父节点，则交换该元素与父节点上的元素
                int temp = heap[(i-1)/2];
                heap[(i-1)/2] = heap[i];
                heap[i] = temp;

                // 别忘记了，还要更新i的索引！
                i = (i-1)/2;
            } 
            size += 1; // 也要更新size的大小
            // 别忘记！该更新的每个量都要小心地更新         

        } else{
            // 当堆容量已经满的时候
            return; 
            // 在我们实现堆的时候，设计为是满的时候不能再插入
            // 当我们在处理“第k大元素”问题的时候，会出现堆满了，然后我们要与堆顶与元素比较大小，如果有需要
            // 手动删掉堆顶原来元素并插入新的元素
        }
    }

    // 为啥insert的时候不用heapify呀？没有很懂

    // Heapify函数，维护堆的父子节点这些大小关系性质（因为我本来只有一个数组）
    // 同时保证了当堆的一部分被改变时（例如，通过插入或删除元素），堆仍然保持其小根堆性质。
    // 所以也是用来恢复堆的性质的函数
    void heapify(int i){
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left<size && heap[left]<heap[smallest]){
            // 因为是小顶堆，所以我们希望的是父节点是最小的
            smallest = left; // note:这里交换只是交换index，下面才要真正交换元素
        }
        if(right<size && heap[right]<heap[smallest]){
            smallest = right;
        }

        // 交换元素
        if(smallest != i){ // 也就是发生了index交换
            int temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;

            heapify(smallest); // 继续递归调用
        }
    }

    // 删除掉堆顶元素（即heap[0])
    void deleteMin(){
        if (size == 0) { // 特判
            cout << "Heap is empty" << endl;
            return;
        }

        heap[0] = heap[size - 1]; // 把最后一个元素替换为堆顶
        size -= 1; //size-1,相当于删掉最后一个元素
        heapify(0); //重新排列堆
    }

    int getMin(){
        if (size == 0) { 
            cout << "Heap is empty" << endl;
            return -1;
        }
        return heap[0];
    }

};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        MinHeap myheap(k);
        if(nums.size()<k){
            return -1;
        }

        // 对前k个元素先无脑加到堆中
        for(int i=0; i<k; i++){
            myheap.insert(nums[i]);
        }

        if(nums.size()>k){
            for(int i=k; i<nums.size(); i++){
                int current_min = myheap.getMin();
                if(nums[i]>current_min){
                    // 比当前的堆顶大，说明当前堆顶并不是第k个最大的元素，把它换掉
                    myheap.deleteMin();
                    myheap.insert(nums[i]);
                }
            }
        } 
        return myheap.getMin();      
    }
};

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    Solution sol;
    int ans = sol.findKthLargest(v,3);
    cout << ans << endl;
}
