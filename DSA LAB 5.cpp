#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
public:
    Node* head;
    SinglyLinkedList() : head(nullptr) {}

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayFirst() { 
        cout << "First node: " << (head ? head->data : -1) << endl; 
    }

    void displayLast() {
        Node* temp = head;
        while (temp && temp->next) {
            temp = temp->next;
        }
        cout << "Last node: " << (temp ? temp->data : -1) << endl;
    }

    void displayNth(int n) {
        Node* temp = head;
        for (int i = 0; temp && i < n; i++) {
            temp = temp->next;
        }
        cout << "Nth node: " << (temp ? temp->data : -1) << endl;
    }

    void displayCenter() {
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next; 
            fast = fast->next->next; 
        }
        cout << "Center node: " << (slow ? slow->data : -1) << endl;
    }
};

void lab5() {
    SinglyLinkedList list;
    for (int val : {10, 20, 30, 40, 50}) {
        list.insertAtEnd(val);
    }

    list.displayFirst();
    list.displayLast();
    list.displayNth(2);
    list.displayCenter();
}

int main() {
    lab5();
    return 0;
}