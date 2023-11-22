#include<iostream>
using namespace std;

#define SIZE 10

class Stack {
    private:
        int top;
        int arr[SIZE];
    public:
        Stack() { top = -1; }
        void push(int value);
        void pop();
        void display();
};

void Stack::push(int value) {
    if (top >= SIZE-1) {
        cout << "Stack Overflow\n";
        return;
    }
    arr[++top] = value;
}

void Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow \n";
        return;
    }
    top--;
}

void Stack::display() {
    if (top < 0) {
        cout << "Stack is empty\n";
        return;
    }
    for(int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

class Queue {
    private:
        int front, rear;
        int arr[SIZE];
    public:
        Queue() { front = -1; rear = -1; }
        void enqueue(int value);
        void dequeue();
        void display();
};

void Queue::enqueue(int value) {
    if (rear >= SIZE-1) {
        cout << "Queue Overflow\n";
        return;
    }
    if (front == -1) {
        front = 0;
    }
    arr[++rear] = value;
}

void Queue::dequeue() {
    if (front > rear || front == -1) {
        cout << "Queue Underflow \n";
        return;
    }
    front++;
}

void Queue::display() {
    if (front > rear || front == -1) {
        cout << "Queue is empty\n";
        return;
    }
    for(int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    Stack s;
    Queue q;
    int choice, value;
    do {
        cout << "\n1. Push to Stack\n2. Pop from Stack\n3. Display Stack\n4. Enqueue to Queue\n5. Dequeue from Queue\n6. Display Queue\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter the value to be pushed: ";
                    cin >> value;
                    s.push(value);
                    break;
            case 2: s.pop();
                    break;
            case 3: s.display();
                    break;
            case 4: cout << "Enter the value to be enqueued: ";
                    cin >> value;
                    q.enqueue(value);
                    break;
            case 5: q.dequeue();
                    break;
            case 6: q.display();
                    break;
            case 7: break;
            default: cout << "Invalid choice\n";
        }
    } while(choice != 7);
    return 0;
}
