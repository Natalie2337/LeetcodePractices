// 通过！
#include <iostream>
using namespace std;
// 两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目

// 位运算：利用XOR异或操作来找出x和y在二进制表示中不同的位，然后统计这些不同的位的数量。
// XOR 操作有一个很好的性质：对于任何数x，与自身进行XOR操作结果为0，而与0进行XOR操作结果为其本身。
// 因此，当我们对x和y进行XOR操作时，只有在他们的某个位不同时，这个位才会被标记出来（即变为1）

//检查最低位：xorResult & 1 检查 xorResult 的最低位是否为1。如果是，说明这是一处差异，因此增加汉明距离计数。
//右移一位：xorResult >>= 1 将 xorResult 向右移动一位，以便在下一次迭代中检查下一个位。这个过程会一直持续到 xorResult 变为0，即所有位都被检查过

class Solution {
public:

    int myxor(int x, int y){
        return x^y;
    }

    int hammingDistance(int x, int y) {
        int rst = x^y; // 进行异或操作
        int count = 0;
        while(rst > 0){
            if(rst & 1 == 1){
                count++;
            }
            rst = rst >> 1;  // 或者 rst >> 1;
        }
        return count;
    }
};

int main(){
    Solution sol;
    int ans = sol.hammingDistance(1,3);
    cout << ans << endl;
}