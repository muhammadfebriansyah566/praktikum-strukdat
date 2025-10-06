#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (stackTop == nullptr) return false;
            char topChar = pop(stackTop);
            if (!isMatching(topChar, c)) return false;
        }
    }

    bool result = (stackTop == nullptr);
    while (stackTop != nullptr) pop(stackTop);
    return result;
}

int main() {
    string expr1 = "{[()]}";
    string expr2 = "{[(])}";

    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;
    return 0;
}
