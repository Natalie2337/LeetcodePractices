#include<iostream>
using namespace std;
bool byteorder_check() {
    int a = 1;
    return (*(char *)&a); /* 1 为小端机，0 为大端机 */
}

int main(){
    bool x = byteorder_check();
    cout << x << endl;
}