#include<iostream>
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
class queue{
    public:
    node* head;
    node* tail;
    int size;
    queue(){
        head=tail=NULL;
        size=0;
    }
    void pushback(int val){
        node* temp = new node(val);
        if(size==0) head=tail=temp;
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    void popfront(){
        if(size==0) {
            cout<<"queue is empty";
            return;
        }
        // node* temp = head;
        head = head->next;
        // delete temp;
        // size--;
        // if(head == NULL) tail = NULL; 
        size--;
    }
    int front(){
         if(size==0) {
            cout<<"queue is empty";
            return -1;
        }
        return head->data;
    }
    int rearorback(){
         if(size==0) {
            cout<<"queue is empty";
            return -2;
        }
        return tail->data;
    }
    void display(){
        node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    queue q;
    q.pushback(10);
    q.pushback(20);
    q.pushback(30);
    q.pushback(80);
    q.pushback(40);
    q.pushback(50);
    q.display();
    q.popfront();
    q.display();
    q.rearorback();
    q.display();
    cout << "Front element: " << q.front() << endl;
    cout << "Rear element: " << q.rearorback() << endl;
}
