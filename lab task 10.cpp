#include <iostream>
using namespace std;

#define STACK_SIZE 100

class ArrayStack {
private:
    int data[STACK_SIZE];
    int topIdx;

public:
    ArrayStack() {
        topIdx = -1;
    }

    void push(int val) {
        if (topIdx >= STACK_SIZE - 1) {
            cout << "Oops! Stack is full\n";
            return;
        }
        data[++topIdx] = val;
    }

    void pop() {
        if (topIdx < 0) {
            cout << "Can't pop from empty stack!\n";
            return;
        }
        cout << "Popped: " << data[topIdx--] << "\n";
    }

    void print() {
        if (topIdx < 0) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack contents: ";
        for (int i = topIdx; i >= 0; --i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

class ListStack {
private:
    struct Node {
        int val;
        Node* next;
    };
    Node* head;

public:
    ListStack() : head(nullptr) {}

    void push(int val) {
        Node* node = new Node;
        node->val = val;
        node->next = head;
        head = node;
    }

    void pop() {
        if (!head) {
            cout << "Stack empty!\n";
            return;
        }
        Node* temp = head;
        cout << "Popped: " << temp->val << "\n";
        head = head->next;
        delete temp;
    }

    void print() {
        if (!head) {
            cout << "Nothing to see here - stack's empty\n";
            return;
        }

        cout << "Stack: ";
        Node* current = head;
        while (current) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~ListStack() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ArrayStack stack1;
    ListStack stack2;

    cout << "Testing array stack:\n";
    stack1.push(42);
    stack1.push(73);
    stack1.push(128);
    stack1.print();
    stack1.pop();
    stack1.print();

    cout << "\nTesting list stack:\n";
    stack2.push(42);
    stack2.push(73);
    stack2.push(128);
    stack2.print();
    stack2.pop();
    stack2.print();

    return 0;
}
