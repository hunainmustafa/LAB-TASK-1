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

    // Insert at Start
    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Display 
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

void lab3() {
    SinglyLinkedList list;

    cout << "Inserting at end: 10" << endl;
    list.insertAtEnd(10);
    list.display();

    cout << "Inserting at start: 5" << endl;
    list.insertAtStart(5);
    list.display();

    cout << "Inserting at end: 20" << endl;
    list.insertAtEnd(20);
    list.display();
}

int main() {
    lab3();
    return 0;
}