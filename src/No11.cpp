// 通过！完全是自己写的！
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l_ptr = 0;
        int r_ptr = height.size()-1;
        int max_water = 0;
        while(l_ptr<r_ptr){
            int left = height[l_ptr];
            int right = height[r_ptr];
            
            if(left<=right){
                int temp = (r_ptr-l_ptr) * left;
                if(temp>max_water){
                    max_water = temp;
                }
                l_ptr += 1;
            }else{
                int temp = (r_ptr-l_ptr) * right;
                if(temp>max_water){
                    max_water = temp;
                }
                r_ptr -= 1;
            }
        }
        return max_water;
    }
};

int main(){
    vector<int> vec = {1,8,6,2,5,4,8,3,7};
    Solution sol;
    int ans = sol.maxArea(vec);
    cout << ans << endl;
}

