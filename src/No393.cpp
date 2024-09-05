// 通过！
// 完全是我自己写的！！
#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

// UTF-8编码验证
// 给定一个表示数据的整数数组 data ，返回它是否为有效的 UTF-8 编码。

// UTF-8 中的一个字符可能的长度为 1 到 4 字节，遵循以下的规则：
// 对于 1 字节 的字符，字节的第一位设为 0 ，后面 7 位为这个符号的 unicode 码。
// 对于 n 字节 的字符 (n > 1)，第一个字节的前 n 位都设为1，第 n+1 位设为 0 ，后面字节的前两位一律设为 10 。剩下的没有提及的二进制位，全部为这个符号的 unicode 码。
// 注意：输入是整数数组。只有每个整数的 最低 8 个有效位 用来存储数据。这意味着每个整数只表示 1 字节的数据。

class Solution {
public:
    unsigned int low8bits0(int x){
        unsigned int ans = x & 0xFF;
        //bitset<8> binary(ans);
        //cout << "Low 8 Binary: " << binary << endl;
        return ans;
    }

    bitset<8> low8bits1(int x){
        unsigned int ans = x & 0xFF;
        bitset<8> binary(ans);
        return binary;
    }

    bool validBytes(vector<int>& data) {
        if(data.size()==0 || data.size()>4){
            return false;
        }

        else if(data.size()==1){
            int num = data[0];
            unsigned int ans = low8bits0(num);
            unsigned int mask = 1 << 8; // 1 << 8的作用是将1（8位二进制表示为00000001，其中1处于最左边）左移8位
            if(ans&mask!=0){
                return false;
            } else{
                return true;
            }
        }
        else{
            // 2,3,4个字节的情况
            int size = data.size();
            int first_byte = data[0];

            //先检查第一个字节
            unsigned int first = low8bits0(first_byte);
            bool flag = true;
            for(int i=0; i<size; i++){
                unsigned int mask = 1 << (8-i);
                if(first&mask==0){
                    flag = false;
                }
            }
            unsigned int mask = 1 << (8-size);
            if(first&mask!=0){
                flag = false;
            }

            // 检查其他的字节
            for(int i=1; i<size; i++){
                int other_byte = data[i];
                unsigned int other = low8bits0(other_byte);
                mask = 1 << 8;
                if(other&mask==0){
                    flag = false;
                }
                mask = 1 << 7;
                if(other&mask!=0){
                    flag = false;
                }
            }
            return flag;
        }
    }

    // 还要考虑一种情况，就是是由不同字符串拼成的
    // 比如[197,130,1]：是有效的 utf-8 编码，为一个 2 字节字符，跟着一个 1 字节字符

    bool validBytesNew(vector<int>& data, int size) {
        if(data.size()!=size){
            cerr << "Wrong Size Input" << endl;
            //throw runtime_error("Wrong Size Input");
        }

        if(size==0 || data.size()>4){
            cerr << "Wrong Data Size!" << endl;
        }

        else if(data.size()==1){
            int num = data[0];
            unsigned int ans = low8bits0(num);
            //unsigned int mask = 1 << 8; // 1 << 8的作用是将1（8位二进制表示为00000001，其中1处于最左边）左移8位
            unsigned int mask = 1 << 7; // 1本来在00000001，只用左移7位就可以到最高位
            //if(ans&mask!=0){ //& has lower precedence than !=
            if((ans&mask)!=0){
                return false;
            } else{
                return true;
            }
        }
        else{
            // 2,3,4个字节的情况
            int size = data.size();
            int first_byte = data[0];

            //先检查第一个字节
            unsigned int first = low8bits0(first_byte);
            bool flag = true;
            for(int i=0; i<size; i++){
                //unsigned int mask = 1 << (8-i); //错误写法
                unsigned int mask = 1 << (7-i);
                //if(first&mask==0){
                if((first&mask)==0){
                    flag = false;
                }
            }
            unsigned int mask = 1 << (7-size);
            if((first&mask)!=0){
                flag = false;
            }

            // 检查其他的字节
            for(int i=1; i<size; i++){
                int other_byte = data[i];
                unsigned int other = low8bits0(other_byte);
                mask = 1 << 7;
                if((other&mask)==0){
                    flag = false;
                }
                mask = 1 << 6;
                if((other&mask)!=0){
                    flag = false;
                }
            }
            return flag;
        }
    }

    void showDataAndMask(unsigned int data, unsigned int mask){
        unsigned int rst = data&mask;
        bitset<8> binary(rst);
        cout << "Low 8 binary result: " << binary << endl;
        //bool check1 = (rst!=0);
        //bool check2 = (rst==0);
        //cout << "check1: " << boolalpha << check1 << endl;
        //cout << "check2: " << boolalpha << check2 << endl;
    }

    bool patternChecker(int original, int choice, int NumofBytes){
        unsigned int data = low8bits0(original);
        unsigned int mask = 1 << 7;

        bitset<8> binary(data);
        cout << "Low 8 binary data: " << binary << endl;

        bitset<8> binary2(mask);
        cout << "Low 8 binary mask: " << binary2 << endl;
        
        bool flag = false;
        bool temp = true;

        if(NumofBytes<0 || NumofBytes>4){
            cerr << "Wrong Input NumofBytes" << endl;
            return false;
        }

        switch(choice){

            case 0:
            //检查是否符合0xxxxxxx形式
                mask = 1 << 7; //检查最高位，需要把1左移7位
                //showDataAndMask(data,mask);
                if((data&mask)==0){
                // if(data&mask==0){
                    // 要注意运算符优先级，如果直接写 if(data&mask==0) 是错误的
                    flag = true;
                }
                break;

            case 1:
            // 检查是否满足1..10x..x的形式
            // NumofBytes就代表有多少个1;
                temp = true;
                for(int i=0; i<NumofBytes; i++){
                    mask = 1 << (7-i);
                    if((data&mask)==0){
                        temp = false;
                    }
                }
                mask = 1 << 7-NumofBytes;
                if((data&mask)!=0){
                    temp = false;
                }
                flag = temp;
                break;

            case 2:
            // 检查是否满足10xx..
                // bool temp = true; //switch中这样在两个case里都重新写bool temp = true 会造成重复定义的错误
                // crosses initialization of 'bool temp'
                // 正确的做法是在最前面先定义一个，在后面赋不同的值
                temp = true;
                mask = 1 << 7;
                if((data&mask)==0){
                    temp = false;
                }
                mask = 1 << 6;
                if((data&mask)!=0){
                    temp = false;
                }
                flag = temp;
                break;

            default:
            //输入不在这三种情况的话,直接break,flag=false
                break;
        }
        return flag;
    }

    bool validHelper(vector<int>& data) {
        vector<unsigned int> low8bits_vec;
        int size = data.size();
        for(int i=0; i<size; i++){
            low8bits_vec.push_back(low8bits0(data[i]));
        }

        if(low8bits_vec.size() != size){
            throw runtime_error("Wrong With Vector Size!");
        }

        int i = 0;
        bool flag = true;
        while(i < size){
            cout << "i: " << i << endl;
            unsigned int data2check = low8bits_vec[i];
            // 首先看是否符合1byte:
            bool one_byte = patternChecker(data2check,0,0);
            if(one_byte){
                cout << "one byte!" << endl;
                i++;           
                continue;
            }

            // 看是否符合2byte:
            bool two_byte_first = patternChecker(data2check,1,2);
            if(two_byte_first){
                i++;
                if(i<size){
                    unsigned int data_second = low8bits_vec[i];
                    bool two_byte_second = patternChecker(data_second,2,0);
                    if(two_byte_second){
                        i++;
                        cout << "two byte!" << endl;
                        continue;
                    }

                }    
            }

            // 看是否符合3byte:
            bool three_byte_first = patternChecker(data2check,1,3);
            if(three_byte_first){
                i++;
                if(i<size){
                    unsigned int data_second = low8bits_vec[i];
                    bool three_byte_second = patternChecker(data_second,2,0);
                    if(three_byte_second){
                        i++;
                        if(i<size){
                            unsigned int data_third = low8bits_vec[i];
                            bool three_byte_third = patternChecker(data_third,2,0);
                            if(three_byte_third){
                                i++;
                                cout << "three byte!" << endl;
                                continue;
                            }
                        }                        
                    }
                }   
            }

            bool four_byte_first = patternChecker(data2check,1,4);
            if(four_byte_first){
                i++;
                if(i<size){
                    unsigned int data_second = low8bits_vec[i];
                    bool four_byte_second = patternChecker(data_second,2,0);
                    if(four_byte_second){
                        i++;
                        if(i<size){
                            unsigned int data_third = low8bits_vec[i];
                            bool four_byte_third = patternChecker(data_third,2,0);
                            if(four_byte_third){
                                i++;
                                if(i<size){
                                    unsigned int data_fourth = low8bits_vec[i];
                                    bool four_byte_fourth = patternChecker(data_fourth,2,0);
                                    if(four_byte_fourth){
                                        i++;
                                        cout << "four byte!" << endl;
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            // 上面都不满足，则不符合要求

            flag = false;
            if(!flag){
                // 中间只要出现不符合条件的，就可以直接终止不再往下走了
                break;
            }
        }
        return flag;        
    }

    bool validUtf8(vector<int>& data) {
        return validHelper(data);
    }

    // 关于代码的优化和改进建议：
//代码重复：你的代码中存在大量的重复逻辑，特别是在检查2字节、3字节和4字节模式时。这使得代码难以阅读和维护。
//可以考虑将重复的逻辑抽象成一个单独的函数，以减少代码重复并提高代码的可读性。
// 比如：
    bool checkMultiBytePattern(vector<unsigned int>& low8bits_vec, int startIdx, int byteCount) {
        bool flag = true;
        for (int i = 0; i < byteCount && startIdx + i < low8bits_vec.size(); ++i) {
            unsigned int data_to_check = low8bits_vec[startIdx + i];
            bool patternMatch = patternChecker(data_to_check, i == 0 ? 1 : 2, i == 0 ? byteCount : 0);
            if (!patternMatch) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};

// int main(){
//     int num = 1234;
//     Solution sol;
//     unsigned int ans = sol.low8bits(num);
//     // bitset<32> binary(ans); // bitset对象binary
//     bitset<8> binary(ans); // bitset对象binary
//     cout << binary << endl;
//     return 0;
// }

// int main(){
//     vector<int> data = {235, 140, 4};
//     Solution sol;
//     bool valid = sol.validBytes(data);
//     //cout << "valid ? " << valid << endl;
//     cout << "valid ? " << boolalpha << valid << endl;
//     return 0;
// }

int main(){
    vector<int> data = {1,197,130,197,130,1};
    Solution sol;
    // bool pattern1 = sol.patternChecker(data[0],0,0);
    // bool pattern2 = sol.patternChecker(data[1],1,2);
    // bool pattern3 = sol.patternChecker(data[2],2,0);
    // cout << "pattern1 ? " << boolalpha << pattern1 << endl;
    // cout << "pattern2 ? " << boolalpha << pattern2 << endl;
    // cout << "pattern3 ? " << boolalpha << pattern3 << endl;
    bool valid = sol.validUtf8(data);
    cout << "valid ? " << boolalpha << valid << endl;
    return 0;
}


