#include <iostream>
using namespace std;
#include <stack>
#include <queue>

class MyStack {

queue<int> q1;
queue<int> q2;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        int temp = q2.front();
        q2.pop();
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return temp;
    }
    
    int top() {
        
        return q1.back();
    }
    
    bool empty() {
        if(q1.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(){
    return 0;
}