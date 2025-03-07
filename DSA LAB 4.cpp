#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = nullptr;
    }

    void insertAtPosition(int val, int pos) {
        Node* newNode = new Node(val);

        if (pos == 0) { 
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {  
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

void lab4() {
    SinglyLinkedList list;

    list.insertAtPosition(10, 0);  
    list.display();

    list.insertAtPosition(20, 1);  
    list.display();

    list.insertAtPosition(15, 1);  
    list.display();

    list.insertAtPosition(5, 0);  
    list.display();

    list.insertAtPosition(30, 10); 
}

int main() {
    lab4();
    return 0;
}