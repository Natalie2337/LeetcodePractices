// 通过！
#include<iostream>
#include<vector>
using namespace std;

// 杨辉三角
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rst;
        vector<int> first_line = {1};
        rst.push_back(first_line);

        if(numRows==1){
            return rst; 
        }

        vector<int> second_line = {1,1};
        rst.push_back(second_line);
        
        if(numRows==2){
            return rst;
        }

        // numRows >= 3
        for(int row=2; row<numRows; row++){
            //vector<int> one_line; 
            //在循环中创建新的向量one_line时，没有指定其初始大小。这会导致编译错误，因为C++不允许对未初始化的向量进行下标访问。
            vector<int> one_line(row+1);
            one_line[0] = 1;
            one_line[row] = 1;
            for(int j=1; j<row; j++){
                one_line[j] = (rst[row-1])[j-1] + (rst[row-1])[j];
            }
            rst.push_back(one_line);
        }
        return rst;
    }
};

int main(){
    int numRows = 5;
    Solution sol;
    vector<vector<int>> ans = sol.generate(numRows);
    cout << "[" ;
    for(int i=0; i<ans.size(); i++){
        vector<int> temp = ans[i];
        cout << "[" ;
        for (int j=0; j<temp.size(); j++){
            cout << temp[j] << ",";
        }
        cout << "]" ;
    }
    cout << "]" << endl;
    return 0;
}