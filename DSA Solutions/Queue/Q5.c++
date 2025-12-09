#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* f = nullptr;
node* r = nullptr;

void enqueue(int d) {
    node* n = new node();
    n->data = d;
    n->next = nullptr;

    if (f == nullptr) {
        f = r = n;
    } else {
        r->next = n;
        r = n;
    }
}

int dequeue() {
    if (f == nullptr) {
        cout << "Queue is Empty\n";
        return -1;
    }

    node* t = f;
    int val = t->data;

    f = f->next;
    delete t;

    return val;
}

int main() {
    int n, t;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t;
        enqueue(t);
    }

    for (int i = 0; i < n; i++) {
        cout << dequeue() << "\n";
    }

    return 0;
}
