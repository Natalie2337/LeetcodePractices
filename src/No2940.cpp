#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        for(auto item : queries){
            // 人只能往右边移动，并且两人交换位置后不影响答案。对于每一次询问不妨设 ai<bi。
            // 如果 heights[ai]<heights[bi]，那么答案就是bi，否则答案在bi右边。
            if()


            //令 hights 的长度为 n，问题转化为在区间 [bi+1,n] 中找到最左边的下标 x 满足 heights[x]>heights[bi]，对于此问题用线段树求解即可。



        }
        
    }
};