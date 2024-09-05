// 通过！完全是自己写的！
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isValidDigit(char x){
        return (x>='1' && x<='9');
    }

    bool isDot(char x){
        return (x=='.');
    }

    bool checkNine(vector<char>& vec){
        if(vec.size()!=9){
            cerr << "Wrong vector size!" << endl;
            return false;
            //throw runtime_error("Wrong With Vector Size!");
        }

        unordered_map<int,int> check_dup;

        for(int i=0; i<vec.size(); i++){
            char temp = vec[i];
            if(isValidDigit(temp)){
                check_dup[temp]++;
            }else{
                if(!isDot(temp)){
                    return false;
                }
            }            
        }
        
        for(auto& pair : check_dup){
            if(pair.second>1){
                //cout << "Has duplicate~" << endl;
                return false;
            }
        }

        return true;     
    }

    bool checklines(vector<vector<char>>& board){
        bool flG = true;
        for(auto & item : board){
            flG = checkNine(item) & flG;
        }
        return flG;
    }

    bool checkCols(vector<vector<char>> & board){

        if(!checkSize(board)) return false;

        // vector<vector<char>> copt;
        // for(int i=0; i<9; i++){
        //     vector<char> temp; // 对于未初始化的vector，不可以取其索引值temp[i]
        //     for(int j=0; j<9; j++){
        //         char c = board[j][i];
        //         temp[j] = c;
        //     }
        //     copt[i] = temp;
        // }

        vector<vector<char>> copt(9, vector<char>(9));

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                copt[i][j] = board[j][i]; 
                //直接使用copt[i][j] = board[j][i];来赋值，无需通过临时向量temp。
            }
        }

        bool b = checklines(copt);
        return b;

    }

    bool checkSize(vector<vector<char>> & board){
        if(board.size() != 9){
            return false;
        }

        for(auto & item : board){
            if(item.size()!= 9){
                return false;
            }
        }

        //cout << "Size OK" << endl;
        return true;
    }

    bool checkASquare(vector<vector<char>> & board, int central_i, int central_j) {  
        if(!checkSize(board)) return false;

        if((central_i <= 0) || (central_i >= 8) || (central_j <= 0) || (central_j >= 8)){
            cerr << "Wrong Input Number of Central Coordinate" << endl;
            return false;
        }

        vector<char> temp;
        for(int i = central_i-1; i <= central_i+1; i++){
            for (int j = central_j-1; j <= central_j+1; j++){
                temp.push_back(board[i][j]);
            }
        }

        bool b = checkNine(temp);
        return b;
    }

    bool checkAllSquares(vector<vector<char>>& board) {
        if(!checkSize(board)) return false;

        bool flag = true;
        for(int i = 1; i<=7; i+=3){
            for(int j=1; j<=7; j+=3){
                bool y = checkASquare(board, i , j);
                flag = flag & y;
            }
        }
        return flag;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        if(!checkSize(board)) return false;
        bool flg = (checklines(board)) & (checkCols(board)) & (checkAllSquares(board));
        return flg;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    bool b = sol.isValidSudoku(board);
    cout << boolalpha << b << endl;
    return 0;

}