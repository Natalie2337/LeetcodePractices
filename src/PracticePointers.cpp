#include<iostream>
using namespace std;

void swap (char *x, char *y) 
{
  char *t = x;
  x = y;
  y = t;
}

int f(int x, int *py, int **ppz) {
    int y, z;
    **ppz += 1;
    z = **ppz;
    *py += 2;
    y = *py;
    x += 3;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    return x + y + z;
}

void square(int *p){
 int a = 10;
 p = &a;
 *p = (*p) * (*p);
}

void increment(int **p){
  (**p)++;
}

int main(){
    // Q1:
    // float f = 10.5;
    // float p = 2.5;
    // float* ptr = &f;
    // (*ptr)++;
    // *ptr = p;
    // cout << *ptr << " " << f << " " << p;

    // // Q2:
    // int *ptr = 0;
    // // int *ptr = 1; //这个甚至不能通过编译！（上面等于0可以通过编译，但是是空指针！）
    // int a = 10;
    // *ptr = a;
    // cout << *ptr << endl;

    // Q3
    // int a = 100, b = 200;
    // int *p = &a, *q = &b;
    // //p = q;
    // *p = *q;
    // cout << "a = " << a << ", b = " << b << endl;
    // cout << "*p = " << *p << ", *q = " << *q << endl;

    //Q4
    // int a = 7;
    // int *c = &a;
    // c = c + 1;
    // cout  << a << "  " << *c << endl;

    //Q5
    // int arr[] = {4, 5, 6, 7};
    // int *p = arr;
    // cout << *p;

    // int arr[] = {1,3,5,7};
    // cout << arr[0] << " ";
    // cout << *arr << " ";

    // cout << arr[1] << " ";
    // cout << *(arr+1) << " ";
    // cout << (*arr)+1 << " ";

    // int arr[] = {4,5,6,7};
    // int *p = arr;

    // *p = 10;
    // cout << arr[0] << endl;
    // cout << *p << endl;

    // *(p+1) = 15;
    // cout << arr[1] << endl;

    // char *ptr; 
    // char Str[] = "abcdefg";
    // ptr = Str;
    // ptr += 5;
    // cout << ptr;

    // char st[] = "ABCD";
    // for(int i = 0; st[i] != '\0'; i++) {
    //     cout << st[i] << *(st)+i << *(i+st) << i[st];
    // }

    //Q6:
    // char *x = "ninjasquiz";
    // char *y = "codingninjas";
    // char *t;
    // swap(x, y);
    // cout<<x << " "<<y;
    // t = x;
    // x = y;
    // y = t; 
    // cout<<" "<<x<< " "<<y;

    // int c, *b, **a;
    // c = 4;
    // b = &c;
    // a = &b;
    // cout << f(c, b, a);

    //Q7
    // int a = 10;
    // square(&a);
    // cout << a << endl;

    // Q8:
    // int num = 10;
    // int *ptr = &num;
    // increment(&ptr);
    // cout << num << endl;

    // int a = 10;
    // int *p = &a;
    // int **q = &p;
    // int b = 20;
    // *q = &b;
    // (*p)++;
    // cout << a << " " << b << endl;
   
    return 0;
}