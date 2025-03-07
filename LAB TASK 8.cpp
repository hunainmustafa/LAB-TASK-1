#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev; // Used for doubly linked list

    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

// Singly Linked List
class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert at end
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

    // Merge two singly linked lists
    void mergeWith(SinglyLinkedList& other) {
        if (!head) {
            head = other.head;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = other.head;
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

// Doubly Linked List
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = tail = nullptr;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Merge two doubly linked lists
    void mergeWith(DoublyLinkedList& other) {
        if (!head) {
            head = other.head;
            tail = other.tail;
            return;
        }
        tail->next = other.head;
        if (other.head)
            other.head->prev = tail;
        tail = other.tail;
    }

    // Display forward
    void displayForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list1, list2;
    list1.insertAtEnd(1);
    list1.insertAtEnd(2);
    list2.insertAtEnd(3);
    list2.insertAtEnd(4);

    cout << "Singly Linked List 1: ";
    list1.display();
    cout << "Singly Linked List 2: ";
    list2.display();

    list1.mergeWith(list2);
    cout << "Merged Singly Linked List: ";
    list1.display();

    DoublyLinkedList dList1, dList2;
    dList1.insertAtEnd(5);
    dList1.insertAtEnd(6);
    dList2.insertAtEnd(7);
    dList2.insertAtEnd(8);

    cout << "Doubly Linked List 1: ";
    dList1.displayForward();
    cout << "Doubly Linked List 2: ";
    dList2.displayForward();

    dList1.mergeWith(dList2);
    cout << "Merged Doubly Linked List: ";
    dList1.displayForward();

    return 0;
}
