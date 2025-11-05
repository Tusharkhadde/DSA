#include <iostream>
using namespace std;

class CircularQueue {
   int* queue;
   int front,rear,maxsize,count;
   public:
   CircularQueue(int size){
        maxsize=size;
        queue = new int[size];
        front=rear=count=0;
   }

   void placeOrder(int orderID){
    if(count==maxsize){
        cout<<"order is full\n";
        return;
    }
    queue[rear]=orderID;
    rear=(rear+1)%maxsize;
    count++;
    cout << "Order " << orderID << " placed successfully.\n";
}
    void serveOrder(){
        if(count==0){
            cout<<"No order t serve:-";
            return;
        }
        cout<<"order"<<queue[front]<<" served\n";
        front=(front+1) % maxsize;
        count--;
    }
    void displayOrders(){
        if(count==0){
            cout<<"No order currently..\n";
            return;
        }
        cout<<"orders:-";
        for(int i=0;i<count;i++){
            int index = (front+i) % maxsize;
            cout<<queue[index]<<" ";
        }
        cout<<endl;
    
   }
};

int main() {
    int m;
    cout << "Enter maximum number of orders (M): ";
    cin >> m;

    CircularQueue q(m);
    int choice, orderID;

    do {
        cout << "\n1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Order ID: ";
                cin >> orderID;
                q.placeOrder(orderID);
                break;
            case 2:
                q.serveOrder();
                break;
            case 3:
                q.displayOrders();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
