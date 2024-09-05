// 通过！
#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <climits>
using namespace std;

// 对数组进行排序：首先，我们需要将给定的整数数组 nums 排序。这是因为我们想要在有序数组中使用两个指针来寻找第三个元素，以便于控制和调整总和以接近目标值。
// 初始化变量：定义一个变量 closestSum 来存储最接近目标值的三个数的和。初始时，可以将其设置为正无穷大或负无穷大，具体取决于目标值的正负。
// 遍历数组：从排序后的数组中取出每一个元素作为基准，然后使用两个指针（左指针和右指针）在剩余的元素中寻找另外两个数，使得这三个数的和最接近目标值。左指针初始化为当前基准元素的下一个位置，右指针初始化为数组的最后一个位置。
// 调整指针并计算和：通过移动左指针向右移动或右指针向左移动来调整总和。如果总和小于目标值，则左指针向右移动以增加总和；如果总和大于目标值，则右指针向左移动以减少总和。在每次调整后，都要检查新的总和是否比之前更接近目标值，如果是，则更新 closestSum。
// 返回结果：遍历完整个数组后，closestSum 就会存储着最接近目标值的三个数的和，返回这个值即可。

class Solution{
    public:
        int threeSumClosest(vector<int> & nums, int target){
            // 首先先给数组排序
            sort(nums.begin(),nums.end());
            int closestSum = INT_MAX;
            for (int i = 0; i < nums.size(); i++){
                int left = i+1;
                int right = nums.size()-1;
                // if( left>=right ) break; // left>=right应该也包含了 left >= nums.size()的情况，所以不用再写一个了
                while(left < right){
                    int sum = nums[left] + nums[right] + nums[i];
                    if (sum<target){
                        if (closestSum == INT_MAX || abs(target-sum) < abs(target-closestSum)){
                            closestSum = sum;
                        }
                        left += 1;
                        //cout << "i: " << i << " left: " << left << " right: " << right << endl;
                    } else if (sum>target){
                        if (closestSum == INT_MAX || abs(target-sum) < abs(target-closestSum)){
                            closestSum = sum;
                        }
                        right -=1;
                        //cout << "i: " << i << " left: " << left << " right: " << right << endl;
                    } else{
                        closestSum = target;
                        return target;
                    }
                }
            }
            return closestSum;
        }
};

int main(){
    vector<int> v = {-1,2,1,-4};
    int target = 1;
    Solution sol;
    int ans = sol.threeSumClosest(v,target);
    cout<< ans << endl;
    return 0;
}