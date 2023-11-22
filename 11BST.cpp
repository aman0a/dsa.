#include<iostream>
#include<sstream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* Insert(Node* root, int data) {
    if(root == NULL) {
        root = GetNewNode(data);
    } else if(data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(Node* root, int data) {
    if(root == NULL) {
        return false;
    } else if(root->data == data) {
        return true;
    } else if(data <= root->data) {
        return Search(root->left, data);
    } else {
        return Search(root->right, data);
    }
}

void Inorder(Node *root) {
    if(root == NULL) return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

Node* FindMin(Node* root) {
    while(root->left != NULL) root = root->left;
    return root;
}

Node* Delete(Node* root, int data) {
    if(root == NULL) return root;
    else if(data < root->data) root->left = Delete(root->left, data);
    else if(data > root->data) root->right = Delete(root->right, data);
    else {
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        } else if(root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if(root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        } else {
            Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    Node* root = NULL;
    int choice;
    do {
        cout << "1. Insert\n2. Delete\n3. Search\n4. Print Inorder\n5. Exit\nEnter your choice: ";
        cin >> choice;
        if(choice == 1) {
            string line;
            cout << "Enter the elements to be inserted (separated by space): ";
            cin.ignore();
            getline(cin, line);
            stringstream ss(line);
            int x;
            while(ss >> x) {
                root = Insert(root, x);
            }
        } else if(choice == 2) {
            int x;
            cout << "Enter the element to be deleted: ";
            cin >> x;
            root = Delete(root, x);
        } else if(choice == 3) {
            int x;
            cout << "Enter the element to be searched: ";
            cin >> x;
            if(Search(root, x) == true) cout << "Found\n";
            else cout << "Not Found\n";
        } else if(choice == 4) {
            Inorder(root);
            cout << "\n";
        }
    } while(choice != 5);

    return 0;
}
