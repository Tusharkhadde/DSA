// #include<iostream>
// using namespace std;
// class node{
//     public:
//         int bit;
//         node* next;
//         node* prev;
//     node(int b){
//         bit=b;
//         next = prev=NULL;
//     }
// };
// class binarynumber{
//     node* head;
//     node* tail;
//     public:
//     binarynumber(){
//         head=tail=NULL;
//     }
//     void insertbit(int b) {
//         node* t = new node(b);
//             if(head==NULL){
//                 head=tail=t;
//             }
//             else{
//                 tail->next=t;
//                 t->prev=tail;
//                 tail=t;
//             }        
//     }
//     void display(){
//         node* temp=head;
//         while(temp==NULL){
//             cout<<temp->bit;
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
//     void ones(){
//         node* temp =head;
//         while(temp!=NULL){
//            if( temp->bit==0) temp->bit=1;
//            else temp->bit=0;
//             temp = temp->next;
//         }
//         cout<<"1's complement: ";
//         display();
//     }
//     void twos(){
//         ones();
//         node* temp = tail;
//         int carry=1;;
//         while(temp && carry ){
//             if(temp->bit==1 && carry==1){
//                 temp->bit=0;
//             }
//             else if(temp->bit==0 & carry==1){
//                 temp->bit=1;
//                 carry=0;
//             }
//             temp = temp->prev;
//         }
//         cout<<"'2's complemct:-";

//         display();
//     }
// };
// int main() {
//     binarynumber num;
//     int n, bit;

//     cout << "Enter number of bits: ";
//     cin >> n;
//     cout << "Enter binary number: ";
//     for (int i = 0; i < n; i++) {
//         cin >> bit;
//         num.insertbit(bit);
//     }

//     cout << "Original Number: ";
//     num.display();

//     num.ones();
//     num.twos();

//     return 0;
// }
#include <iostream>
using namespace std;

class Node {
public:
    int bit;
    Node* next;
    Node* prev;

    Node(int b) {
        bit = b;
        next = prev = NULL;
    }
};

class BinaryNumber {
    Node* head;
    Node* tail;

public:
    BinaryNumber() {
        head = tail = NULL;
    }

    void insertBit(int b) {
        Node* newNode = new Node(b);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->bit;
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to compute 1's complement
    void onesComplement() {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->bit == 0)
                temp->bit = 1;
            else
                temp->bit = 0;
            temp = temp->next;
        }

        cout << "1's Complement: ";
        display();
    }

    // Function to compute 2's complement
    void twosComplement() {
        // Step 1: Flip bits manually (same as 1’s complement)
        Node* temp = head;
        while (temp != NULL) {
            if (temp->bit == 0)
                temp->bit = 1;
            else
                temp->bit = 0;
            temp = temp->next;
        }

        // Step 2: Add 1 to the least significant bit
        temp = tail;
        int carry = 1;
        while (temp != NULL && carry) {
            if (temp->bit == 1 && carry == 1) {
                temp->bit = 0; // 1+1 = 0 (carry stays 1)
            } else if (temp->bit == 0 && carry == 1) {
                temp->bit = 1; // 0+1 = 1 (carry becomes 0)
                carry = 0;
            }
            temp = temp->prev;
        }

        cout << "2's Complement: ";
        display();
    }
};

int main() {
    BinaryNumber num;
    int n, bit;

    cout << "Enter number of bits: ";
    cin >> n;
    cout << "Enter binary number: ";
    for (int i = 0; i < n; i++) {
        cin >> bit;
        num.insertBit(bit);
    }

    cout << "Original Number: ";
    num.display();

    num.onesComplement();
    num.twosComplement();

    return 0;
}
