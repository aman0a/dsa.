#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void insert(Node** head, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

void deleteNode(Node **head, int key) {
    Node* temp = *head, *prev;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        delete temp;
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    delete temp;
}

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

bool search(Node* head, int x) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}

void reverse(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    Node* head = NULL;
    int choice, data;
    while (1) {
        cout << "\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Reverse\n6.Exit\n";
        cin >> choice;
        switch (choice) {
        case 1: cout << "Enter the element: ";
            cin >> data;
            insert(&head, data);
            break;
        case 2: cout << "Enter the element to be deleted: ";
            cin >> data;
            deleteNode(&head, data);
            break;
        case 3: printList(head);
            break;
        case 4: cout << "Enter the element to be searched: ";
            cin >> data;
            search(head, data) ? cout << "Yes" : cout << "No";
            break;
        case 5: reverse(&head);
            break;
        case 6: exit(0);
        default: cout << "Invalid choice!";
        }
    }
    return 0;
}
