#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

class singly {
    node* head;
public:
    singly() {
        head = NULL;
    }

    // Insert node at end
    void insert(int val) {
        node* A = new node(val);
        if (head == NULL) {
            head = A;
            return;
        }
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = A;
    }

    // Delete a node
    void deletenode(int val) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        if (head->data == val) {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        node* temp = head;
        while (temp->next && temp->next->data != val)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "Element not found\n";
            return;
        }

        node* delnode = temp->next;
        temp->next = temp->next->next;
        // delete delnode;
    }

    // Display the list
    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Search for an element
    void search(int val) {
        node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == val) {
                cout << "Element found at position " << pos << endl;
                return;
            }
            pos++;
            temp = temp->next;
        }
        cout << "Element not found\n";
    }

    // Reverse the list
    void rev() {
        node* curr = head;
        node* Next = NULL;
        node* prev = NULL;
        while (curr) {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        head = prev;
        cout << "List reversed successfully.\n";
        display();
    }

    // Find middle node
    void findMiddle() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        node* slow = head;
        node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << endl;
    }
};

int main() {
    singly list;
    int choice, val;

    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Display\n4. Search\n5. Reverse\n6. Find Middle\n7. Exit\nEnter choice: ";
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
            list.deletenode(val);
            break;
        case 3:
            list.display();
            break;
        case 4:
            cout << "Enter value to search: ";
            cin >> val;
            list.search(val);
            break;
        case 5:
            list.rev();
            break;
        case 6:
            list.findMiddle();
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
