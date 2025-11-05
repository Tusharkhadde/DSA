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
class list{
    node* head;
    public:
    list(){head=NULL;}
    void insert(int ins){
        node* t = new node(ins);
        if(head==NULL){
            head=t;
            return;
        }
        node* temp =head;
        while(temp->next!=NULL){
            temp=temp->next;
        }        
            temp->next = t;
    }
    int middle(){
        node* slow=head;
        node* fast=head;
        while(fast!=NULL && fast->next!=NULL ){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;

    }
    void printList() {
        node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main(){
    list l;
    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.insert(50);
    l.printList();
    l.middle();
    l.printList();
}