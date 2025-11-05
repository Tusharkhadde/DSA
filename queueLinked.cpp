#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Queue class using linked list
class Queue {
private:
    Node* front; // points to front node
    Node* rear;  // points to rear node

public:
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node(value);

        // If queue is empty
        if (rear == nullptr) {
            front = rear = newNode;
            cout << value << " enqueued successfully.\n";
            return;
        }

        // Add new node at end
        rear->next = newNode;
        rear = newNode;
        cout << value << " enqueued successfully.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        // If queue becomes empty
        if (front == nullptr)
            rear = nullptr;

        cout << temp->data << " dequeued successfully.\n";
        delete temp;
    }

    // Peek (see front element)
    void peek() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front element: " << front->data << endl;
    }

    // Display all elements
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
    q.peek();

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue(); // testing empty queue

    return 0;
}
