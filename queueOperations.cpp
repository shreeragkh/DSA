#include <iostream>
using namespace std;

class queueOperations
{
    int* queue;
    int size;
    int front, rear;
public:
    queueOperations(int size){
        this->size = size;
        queue = new int[size];
        front = rear = -1;
    }
    ~queueOperations(){
        delete[] queue;
    }
    void enqueue(int val){
        if(rear == size - 1){
            cout << "Queue overflow" << endl;
        }
        else{
            rear++;
            queue[rear] = val;
            if(front == -1){
                front = 0;
            }
        }
    }
    int dequeue(){
        if(front == -1 || front > rear){
            cout << "Queue underflow" << endl;
            return -1;
        }
        else{
            int temp = queue[front];
            front++;
            if(front > rear){
                front = rear = -1;
            }
            return temp;
        }
    }
    void display(){
        if(front == -1 || front > rear){
            cout << "Queue is empty" << endl;
        }
        else{
            for(int i = front; i <= rear; i++){
                cout << queue[i] << "->";
            }
            cout << endl;
        }
    }
    void peek(){
        if(front == -1 || front > rear){
            cout << "Queue is empty" << endl;
        }
        else{
            cout << queue[front] << endl;
        }
    }
};

int main(){
    cout << "Enter the size of queue:" << endl;
    int size;
    cin >> size;
    queueOperations q(size);
    while (true){
        cout << "1.Enqueue \n2.Dequeue \n3.Display \n4.Peek \n5.Exit" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:{
            int val;
            cin >> val;
            q.enqueue(val);
            break;
        }
        case 2:
            cout << q.dequeue() << endl;
            break;
        case 3:
            q.display();
            break;
        case 4:
            q.peek();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}

