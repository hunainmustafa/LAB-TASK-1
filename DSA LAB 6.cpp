#include <iostream> 
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
public:
    Node* head = nullptr;

    void insertAtEnd(int val) {
        Node** temp = &head;
        while (*temp) temp = &((*temp)->next);
        *temp = new Node(val);
    }

    void deleteFirst() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLast() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteNth(int pos) {
        if (!head) return;
        if (pos == 0) return deleteFirst();
        Node* temp = head;
        for (int i = 1; temp && temp->next && i < pos; i++) temp = temp->next;
        if (!temp || !temp->next) return;
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void deleteCenter() {
        if (!head || !head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete slow;
    }

    void display() {
        for (Node* temp = head; temp; temp = temp->next) cout << temp->data << " -> ";
        cout << "NULL" << endl;
    }
};

void lab6() {
    SinglyLinkedList list;
    for (int val : {10, 20, 30, 40, 50, 60}) list.insertAtEnd(val);

    cout << "Initial List:\n"; 
    list.display();
    
    cout << "Deleting first node...\n"; 
    list.deleteFirst();
    list.display();
    
    cout << "Deleting last node...\n"; 
    list.deleteLast();
    list.display();
    
    cout << "Deleting Nth node (position 2)...\n"; 
    list.deleteNth(2);
    list.display();
    
    cout << "Deleting center node...\n"; 
    list.deleteCenter();
    list.display();
}

int main() {
    lab6();
    return 0;
}
