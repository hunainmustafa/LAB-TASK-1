#include <iostream>
using namespace std;

#define MAX_QUEUE_SIZE 100

class ArrayQueue {
private:
    int elements[MAX_QUEUE_SIZE];
    int head;
    int tail;

public:
    ArrayQueue() {
        head = tail = -1;
    }

    void add(int x) {
        if (tail >= MAX_QUEUE_SIZE - 1) {
            cout << "Queue's full! Can't add more elements :(\n";
            return;
        }
        if (head == -1) head = 0;
        elements[++tail] = x;
    }

    void remove() {
        if (isEmpty()) {
            cout << "Nothing to remove - queue's empty!\n";
            return;
        }
        cout << "Removed: " << elements[head++] << "\n";
    }

    bool isEmpty() {
        return (head == -1 || head > tail);
    }

    void showAll() {
        if (isEmpty()) {
            cout << "Queue is empty right now\n";
            return;
        }
        cout << "Current queue: ";
        for (int i = head; i <= tail; i++) {
            cout << elements[i];
            if (i != tail) cout << " -> ";
        }
        cout << endl;
    }
};

class ListQueue {
private:
    struct QNode {
        int value;
        QNode* next;
        QNode(int v) : value(v), next(nullptr) {}
    };

    QNode *head, *tail;

public:
    ListQueue() : head(nullptr), tail(nullptr) {}

    void add(int x) {
        QNode* newNode = new QNode(x);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void remove() {
        if (!head) {
            cout << "Queue's empty!\n";
            return;
        }
        QNode* temp = head;
        cout << "Removed: " << temp->value << "\n";
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
    }

    void showAll() {
        if (!head) {
            cout << "Nothing to show - queue's empty\n";
            return;
        }
        cout << "Queue contents: ";
        QNode* current = head;
        while (current) {
            cout << current->value;
            if (current->next) cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }

    ~ListQueue() {
        while (head) {
            QNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ArrayQueue q1;
    ListQueue q2;

    cout << "Testing array queue:\n";
    q1.add(42);
    q1.add(17);
    q1.add(99);
    q1.showAll();
    q1.remove();
    q1.showAll();

    cout << "\nTesting list queue:\n";
    q2.add(42);
    q2.add(17);
    q2.add(99);
    q2.showAll();
    q2.remove();
    q2.showAll();

    return 0;
}
