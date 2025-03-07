#include <iostream> 
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = tail = nullptr;
    }

    void insertAtFirst(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtLast(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtNth(int val, int pos) {
        if (pos == 0) {
            insertAtFirst(val);
            return;
        }
        
        Node* temp = head;
        for (int i = 1; temp && i < pos; i++) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode;  

        temp->next = newNode;
    }

    void insertAtCenter(int val) {
        if (!head) {
            insertAtFirst(val);
            return;
        }

        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* newNode = new Node(val);
        newNode->next = slow->next;
        newNode->prev = slow;

        if (slow->next)
            slow->next->prev = newNode;
        else
            tail = newNode; 

        slow->next = newNode;
    }

    void displayForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayBackward() {
        Node* temp = tail;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

void lab7() {
    DoublyLinkedList list;
    
    list.insertAtFirst(10);
    list.insertAtLast(20);
    list.insertAtLast(30);
    list.insertAtLast(40);
    list.insertAtCenter(25);
    list.insertAtNth(15, 2);

    cout << "Doubly Linked List (Forward): ";
    list.displayForward();

    cout << "Doubly Linked List (Backward): ";
    list.displayBackward();
}

int main() {
    lab7();
    return 0;
}
