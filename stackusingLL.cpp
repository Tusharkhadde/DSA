#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
class stack{
    node* top;
    public:
    stack(){top=NULL;}
    void push(int val)
    {
        node* t = new node(val);
        t->next = top;
        top=t;
        cout<<val<<"pushed success\n";

    }
    void pop(){
        if(top==NULL){
            cout<<"stack is empty\n";
            return;
        }
        cout<<top->data<<"pop\n";
        node* temp =top;
        top=top->next;
        delete temp;
    }
    void front(){
         if (top == NULL) {
            cout << "Stack is empty\n";
        } else {
            cout << "Top element: " << top->data << "\n";
        }
    }
    void display(){
        if(top==NULL){
            cout<<"stack is empty\n";
            return;
        }
        node* temp = top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
    int main() {
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.front();
    s.pop();
    s.display();
    return 0;
}
