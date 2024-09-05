#include <iostream>
#include <memory>
using namespace std;

class SmartPtr {
    int* ptr; 
public:
    explicit SmartPtr(int* p = NULL) { ptr = p; }
    ~SmartPtr() { delete (ptr); }
    int& operator*() { return *ptr; }
};

class Rectangle{
    int length;
    int breadth;

public:
    Rectangle(int l, int b){
        this->length = l;
        this->breadth = b;
    }

    int area(){
        return length * breadth;
    }
};

class B;

class A{
public:
    shared_ptr<B> b_;
    A(){
        cout << "A constructed!" << endl;
    }
    ~A(){
        cout << "A destructed!" << endl;
    }
};

class B{
public:
    shared_ptr<A> a_;
    B(){
        cout << "B constructed!" << endl;
    }
    ~B(){
        cout << "B destructed!" << endl;
    }
};

int main()
{
    // SmartPtr ptr(new int());
    // *ptr = 20;
    // cout << *ptr;
    // return 0;

    // unique_ptr<Rectangle> P1(new Rectangle(10,5));
    // cout << P1->area() << endl;
    // unique_ptr<Rectangle> P2;
    // //unique_ptr<Rectangle> P2(P1);
    // //P2 = P1;
    // P2 = move(P1);

    // cout << P2->area() << endl;
    // //cout << P1->area() << endl;
    // return 0;

    // shared_ptr<Rectangle> P1(new Rectangle(10,5));
    // cout << P1->area() << endl;
    // shared_ptr<Rectangle> P2;
    // P2 = P1;

    // cout << P2->area() << endl;
    // cout << P1->area() << endl;
    // cout << P1.use_count() << endl;
    // return 0;

    auto classA = make_shared<A>();
    auto classB = make_shared<B>();
    classA-> b_ = classB;
    classB-> a_ = classA;
    cout << "A: " << classA.use_count() << endl;
    cout << "B: " << classB.use_count() << endl;
    return 0;
}

