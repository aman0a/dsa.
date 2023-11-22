#include<iostream>
#include<string>
#define MAX 100

using namespace std;

class Stack {
    int top;
    char a[MAX];

public:
    Stack() { top = -1; }
    bool push(char x);
    char pop();
    char peek();
    bool isEmpty();
};

bool Stack::push(char x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        return true;
    }
}

char Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        char x = a[top--];
        return x;
    }
}

char Stack::peek() {
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        char x = a[top];
        return x;
    }
}

bool Stack::isEmpty() {
    return (top < 0);
}

int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}

int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return 0;
}

string infixToPostfix(string infix) {
    Stack stack;
    string postfix;
    for (int i = 0; i < infix.length(); i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            postfix += infix[i];
        }
        else if (isOperator(infix[i]) == 1) {
            if (stack.isEmpty())
                stack.push(infix[i]);
            else {
                while (!stack.isEmpty() && precedence(infix[i]) <= precedence(stack.peek())) {
                    postfix += stack.peek();
                    stack.pop();
                }
                stack.push(infix[i]);
            }
        }
    }
    while (!stack.isEmpty()) {
        postfix += stack.peek();
        stack.pop();
    }
    return postfix;
}

int main() {
    string infix_exp, postfix_exp;
    cout << "Enter a Infix Expression : ";
    cin >> infix_exp;
    postfix_exp = infixToPostfix(infix_exp);
    cout << "Postfix Expression: " << postfix_exp;
    return 0;
}
