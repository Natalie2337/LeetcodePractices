// 通过！
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 合并区间
// 我们将列表中的区间按照左端点升序排序。然后我们将第一个区间加入 merged 数组中，并按顺序依次考虑之后的每个区间：
// 如果当前区间的左端点在数组 merged 中最后一个区间的右端点之后，那么它们不会重合，我们可以直接将这个区间加入数组 merged 的末尾；
// 否则，它们重合，我们需要用当前区间的右端点更新数组 merged 中最后一个区间的右端点，将其置为二者的较大值。

// 在 C++ 中，当我们想要对一组对象进行排序时，而这些对象的默认排序方式并不满足我们的需求，我们就需要提供一种自定义的比较方法。在这种情况下，我们可以定义一个函数对象（也称为仿函数），它可以作为 std::sort 函数的第三个参数，用于指定排序的规则。
//CompareStart 就是一个这样的函数对象，它定义了一个重载的调用运算符 operator()。这个运算符接受两个参数（在本例中是两个 vector<int> 类型的区间），并返回一个布尔值，表示第一个参数是否应该排在第二个参数之前。
struct CompareStart{
    bool operator()(vector<int> & a, vector<int> & b){
        return a[0] < b[0];
    }
};

class Solution{
    public:
        vector<vector<int>> merge(vector<vector<int>> & intervals){
            for(int i=0; i<intervals.size(); i++){
                if(intervals[i].size()!=2){
                    cout << "Error: interval size is not correct" << endl;
                    break;
                }
                if(intervals[i][0] > intervals[i][1]){
                    cout << "Error: interval number is not correct" << endl;
                    break;
                }   
            }
            sort(intervals.begin(),intervals.end(),CompareStart()); //  按照左端点升序排序
            vector<vector<int>> merged;
            for (int i=0; i<intervals.size(); i++){
                if( merged.size()==0 || intervals[i][0] > merged.back()[1]){
                    // 如果当前区间的左端点在数组 merged 中最后一个区间的右端点之后，那么它们不会重合，我们可以直接将这个区间加入数组 merged 的末尾
                    merged.push_back(intervals[i]);
                } else{
                    // 否则，它们重合，我们需要用当前区间的右端点更新数组 merged 中最后一个区间的右端点，将其置为二者的较大值
                    merged.back()[1] = max(merged.back()[1], intervals[i][1]);
                }                
            }
            return merged;
        }
};

int main(){
    vector<vector<int>> v = {{1,3},{2,6},{8,10},{15,18}};
    Solution sol;
    vector<vector<int>> ans = sol.merge(v);
    cout << "[";
    for (int i=0; i<v.size(); i++){
        cout << "[" << v[i][0] << "," << v[i][1] << "]" << ",";
    }
    cout << "]" << endl;
}
