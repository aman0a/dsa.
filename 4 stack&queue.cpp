#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    private:
        Node* top;
    public:
        Stack() { top = NULL; }
        void push(int value);
        void pop();
        void display();
};

void Stack::push(int value) {
    Node* newNode = new Node;
    if (!newNode) {
        cout << "Heap overflow";
        exit(1);
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void Stack::pop() {
    if (top == NULL) {
        cout << "Underflow \n";
        return;
    }
    Node* temp = top;
    top = top->next;
    temp->next = NULL;
    delete temp;
}

void Stack::display() {
    Node* temp;
    if (top == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    temp = top;
    while (temp != NULL) {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
}

class Queue {
    private:
        Node *front, *rear;
    public:
        Queue() { front = rear = NULL; }
        void enqueue(int value);
        void dequeue();
        void display();
};

void Queue::enqueue(int value) {
    Node* newNode = new Node;
    if (!newNode) {
        cout << "Heap overflow";
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void Queue::dequeue() {
    if (front == NULL) {
        cout << "Underflow \n";
        return;
    }
    Node* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    delete temp;
}

void Queue::display() {
    Node* temp = front;
    if ((front == NULL) && (rear == NULL)) {
        cout << "Queue is empty\n";
        return;
    }
    while (temp != NULL) {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
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
