#include <iostream>
#include <queue>
using namespace std;
class StackusingQueue{
    queue<int>q1 , q2;
    public:
    void push(int x){
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    void pop(){
        if(q1.empty()) {
            cout<<"Stack is empty\n";
            return;
        }
        q1.pop();
    }
    int top(){
        if(q1.empty()){
            cout<<"stack is empty\n";
            return -1;
        }
        return q1.front();
    }
};