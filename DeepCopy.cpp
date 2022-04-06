#include <iostream>
using namespace std;

class Person{
public:
    Person(){
        cout<<"无参构造函数。"<<endl;
    }
    Person(int age, int height){
        mAge = age;
        mHeight = new int(height);
        cout << "有参构造函数。" << endl;
    }
    Person(const Person& p){
        mAge = p.mAge;
        mHeight = new int(*p.mHeight);
        cout << "拷贝构造函数。" << endl;
    }
    ~Person(){
        if(mHeight != NULL){
            delete mHeight;
            mHeight = NULL;
        }
        cout << "析构函数。" << endl;
    }
    int mAge;
    int *mHeight;
};

void test(){
    Person p1(18, 160);
    cout << "P1 age is: " << p1.mAge <<" Height is "<< *p1.mHeight << endl;
    Person p2(p1);
    cout << "P2 age is: " << p2.mAge <<" Height is "<< *p2.mHeight << endl;
}

int main(){
    test();
    return 0;
}