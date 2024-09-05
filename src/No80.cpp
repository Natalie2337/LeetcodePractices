// 通过！完全是自己想的～
#include<iostream>
#include<vector> 
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size<=2) {
            return size;
        }
        for(int i=2; i<size; i++){
            if((nums[i] == nums[i-1]) && (nums[i] == nums[i-2])){
                nums.erase(nums.begin()+i);
                i -= 1;
                size -= 1;
            }
        }   
        return size; 
    }
};

int main(){
    Solution sol;
    vector<int> vec = {0,0,1,1,1,1,2,3,3};
    int s = sol.removeDuplicates(vec);
    cout << s << endl;
    return 0;
}