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
class circular {
    node* head;
public:
    circular() {
        head = NULL;
    }
    void insert(int ins){
        node* t = new node(ins);
        if(head==NULL){
            head=t;
            head->next=head;
            return;
        }
        node* temp = head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next = t;
        t->next =head;
    }
    void del(int val){
        if(head==NULL) return;
        if(head->next==head && head->data==val){
            delete head;
            head=NULL;
            return;
        }
        node* curr=head;
        node* prev = NULL;
        if(head->data==val){
            if(head->next==head){
                delete head;
                head=NULL;
                return;
            }
            node* last =head;
            while(last->next!=head){
                last = last->next;
            }
            last->next = head->next;
            node* temp = head;
            head=head->next;
            delete temp;
            return;
        }
        while(curr->next!=head && curr->data !=val){
            prev=curr;
            curr =curr->next;           
        }
        if(curr->data==val){
            prev->next = curr->next;
            delete curr;
        }
        else{
            cout<<"NOt found";
        }
    }
    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        node* temp = head;
        while (true) {
            cout << temp->data << " ";
            temp = temp->next;
            if (temp == head)
                break;
        }
        cout << endl;
    }
};

int main() {
    circular s;
    s.insert(10);
    s.insert(20);
    s.insert(30);

    cout << "After inserts: ";
    s.display();

    s.del(20);
    cout << "After deleting 20: ";
    s.display();

    s.del(10);
    cout << "After deleting 10: ";
    s.display();

    s.del(30);
    cout << "After deleting 30: ";
    s.display();

    return 0;
}