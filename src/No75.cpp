// 通过！
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;
        int blue = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) {
                red += 1;
            }else if(nums[i] == 1){
                white += 1;
            }else if(nums[i] == 2){
                blue += 1;
            }else{
                cerr << "Wrong Input" << endl;
            }   
        }  

        if(nums.size() != (red+white+blue-1)){
            cerr << "Wrong Counting Numbers" << endl;
        }

        for(int i=0; i<nums.size(); i++){
            if(i <= red-1){
                nums[i] = 0;
            } else if(i<=red+white-1){
                nums[i] = 1;
            } else {
                nums[i] = 2;
            } 
        }
    }
};