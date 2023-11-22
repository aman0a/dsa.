#include<iostream>
#include<sstream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head;

void InsertAtHead(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void Delete(int x) {
    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == x) {
            if(temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            if(temp->prev != NULL) {
                temp->prev->next = temp->next;
            }
            if(temp == head) {
                head = temp->next;
            }
            delete temp;
            return;
        }
        temp = temp->next;
    }
    cout << "Element not found in the list\n";
}

void Search(int x) {
    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == x) {
            cout << "Element found in the list\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Element not found in the list\n";
}

void Print() {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    head = NULL;
    int choice;
    do {
        cout << "1. Insert\n2. Delete\n3. Search\n4. Print\n5. Exit\nEnter your choice: ";
        cin >> choice;
        if(choice == 1) {
            string line;
            cout << "Enter the elements to be inserted (separated by space): ";
            cin.ignore();
            getline(cin, line);
            stringstream ss(line);
            int x;
            while(ss >> x) {
                InsertAtHead(x);
            }
        } else if(choice == 2) {
            int x;
            cout << "Enter the element to be deleted: ";
            cin >> x;
            Delete(x);
        } else if(choice == 3) {
            int x;
            cout << "Enter the element to be searched: ";
            cin >> x;
            Search(x);
        } else if(choice == 4) {
            Print();
        }
    } while(choice != 5);

    return 0;
}

