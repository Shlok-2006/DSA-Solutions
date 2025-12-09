#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* front = nullptr;
node* rear = nullptr;

void linkedListTraversal(node* ptr) {
    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

void enqueue(int d) {
    node* new_n = new node();
    new_n->data = d;
    new_n->next = nullptr;

    if (front == nullptr) {
        front = rear = new_n;
    } else {
        rear->next = new_n;
        rear = new_n;
    }
}

int dequeue() {
    if (front == nullptr) {
        cout << "Queue is Empty\n";
        return -1;
    }

    node* ptr = front;
    int val = ptr->data;

    front = front->next;
    delete ptr;

    return val;
}

int main() {
    int n, t;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t;
        enqueue(t);
    }

    linkedListTraversal(front);
    dequeue();
    cout << "\n";
    linkedListTraversal(front);

    return 0;
}
