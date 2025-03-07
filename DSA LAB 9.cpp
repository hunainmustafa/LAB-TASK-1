#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev; // Used for Doubly Circular Linked List (if needed)

    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

// Circular Singly Linked List
class CircularSinglyLinkedList {
public:
    Node* head;

    CircularSinglyLinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtFirst(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Insert at the end
    void insertAtLast(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Insert at a specific position
    void insertAtNth(int val, int pos) {
        if (pos == 0) {
            insertAtFirst(val);
            return;
        }

        Node* temp = head;
        for (int i = 1; temp->next != head && i < pos; i++) {
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Insert in the middle
    void insertAtCenter(int val) {
        if (!head) {
            insertAtFirst(val);
            return;
        }

        Node* slow = head;
        Node* fast = head;
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* newNode = new Node(val);
        newNode->next = slow->next;
        slow->next = newNode;
    }

    // Display the list
    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(Back to Head)" << endl;
    }

    // Delete a node at a given position
    void deleteAtNth(int pos) {
        if (!head) return;

        Node* temp = head, *prev = nullptr;
        if (pos == 0) {  // Delete the first node
            while (temp->next != head) temp = temp->next;
            if (head == temp) {  // Only one node
                delete head;
                head = nullptr;
                return;
            }
            temp->next = head->next;
            delete head;
            head = temp->next;
            return;
        }

        for (int i = 0; temp->next != head && i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp->next == head) return; // Invalid position

        prev->next = temp->next;
        delete temp;
    }
};

int main() {
    CircularSinglyLinkedList list;
    
    list.insertAtFirst(10);
    list.insertAtLast(20);
    list.insertAtLast(30);
    list.insertAtLast(40);
    list.insertAtCenter(25);
    list.insertAtNth(15, 2);

    cout << "Circular Singly Linked List: ";
    list.display();

    list.deleteAtNth(2);
    cout << "After Deletion: ";
    list.display();

    return 0;
}
