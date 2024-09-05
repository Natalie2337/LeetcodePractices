// 通过！
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<cctype>
#include<cstdint>
#include<cstdlib>
using namespace std;

// 逆波兰表达式：
// 逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。

// 平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
// 该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。

// 逆波兰表达式主要有以下两个优点：
// 去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
// 适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中

// 逆波兰表达式（Reverse Polish Notation，RPN）是一种后缀表达式，只包含数字和运算符。计算逆波兰表达式的基本思路是：
// 从左到右遍历逆波兰表达式。
// 遇到数字时，将其压入栈中。
// 遇到运算符时，从栈顶取出两个元素进行运算，然后将结果压回栈中。
// 重复步骤2和3，直到遍历完整个表达式。
// 最后，栈中的唯一元素就是表达式的结果。

class Solution {
public:

    int isOperator(string &str){
        if (str == "+" || str == "-" || str == "*" || str == "/") return 1;
        else return 0;
    }

    // 假设输入都是合法的数字字符串或者运算符号，没有奇怪的运算符号

    int evalRPN(vector<string>& tokens) {
        stack<int32_t> s;
        for(int i=0; i<tokens.size(); i++){
            string temp = tokens[i];
            if(!isOperator(temp)){
                int32_t number = std::stoi(temp);
                s.push(number);
            } else{
                int32_t val1 = s.top();
                s.pop();
                // top()函数只返回栈顶元素的引用，但并不移除它。如果你想要移除栈顶元素，同时也获得它的值，你需要先使用top()获取值，然后调用pop()移除元素

                int32_t val2 = s.top();
                s.pop();

                char op = temp[0];
                switch(op){
                    case '+':
                        s.push(val2+val1);
                        break;
                    case '-':
                        s.push(val2-val1); // 减法和除法的顺序别弄反了
                        break;
                    case '*':
                        s.push(val2*val1);
                        break;
                    case '/':
                        if(val1 == 0){
                            cerr << "Error: Division by zero." << endl;
                            return -1; 
                        }
                        s.push(val2/val1);
                        break;
                        // 两个整数之间的除法向零截断就是直接这样除，只保留整数部分，小数部分四舍五入
                }
            }
        }
        if(s.size()==1){
            return s.top();
        } else{
            cerr << "Error: Wrong Expression." << endl;
            return -1;
        }   
    }
};

int main(){
    vector<string> v = {"4","13","5","/","+"};
    Solution sol;
    int a = sol.evalRPN(v);
    cout << a << endl;
}