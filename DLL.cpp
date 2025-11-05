#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int val){
        data=val;
        prev=next=NULL;
    }
};
class DLL{
    Node* head;
    public:
    DLL(){
        head=NULL;
    }
    void insert(int val){
        Node* t= new Node(val);
        if(head=NULL){
            head=t;
            head->next=head->prev = head;
            return;
        }
        Node *tail=head->prev;
        tail->next = t;
        t->prev=tail;
        t->next=head;
        head->prev = t;
    }
    void deleteNode(int val){
        if(head==NULL){
            cout<<"List is empty!\n";
            return;
        }
        Node* curr =head;
        while(curr->next!=NULL && curr->data!=val){
            curr=curr->next;
        }
        if(curr->data!=val){
            cout<<"not found\n";
            return;
        }
        if(curr->next==curr){
            delete curr;
            head=NULL;
            return;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        if(curr=head) head=curr->next;
        delete curr;
    }
    void display(){
        if(head==NULL){
            cout<<"List is empty!\n";
            return;
        }
        Node* temp =head;
        while(true){
            cout<<temp->data<<"<->";
            temp=temp->next;
            if(temp==head) break;
        }
        cout<<"head\n";
    }
    
};
int main() {
    DLL list;
    int choice, val, pos;

    while (2>0) {
        cout << "\n--- Doubly Circular Linked List Menu ---\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert at Specific Position\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insert(val);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            list.deleteNode(val);
            break;
        // case 3:
        //     list.display();
        //     break;
        // case 4:
        //     cout << "Enter value to search: ";
        //     cin >> val;
        //     list.search(val);
        //     break;
        // case 5:
        //     return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}