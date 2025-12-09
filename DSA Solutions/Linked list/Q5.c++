#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
} *start = nullptr;

void display() {
    node* temp = start;
    cout << "Linked List:";
    while (temp != nullptr) {
        cout << "->" << temp->data;
        temp = temp->next;
    }
}

void deleteNode(node*& head, int val) {
    if (head == nullptr)
        return;

    if (head->data == val) {
        node* t = head;
        head = head->next;
        delete t;
        return;
    }

    deleteNode(head->next, val);
}

int main() {
    int n;
    cin >> n;

    node* temp;
    node* p2;
    start = nullptr;

    for (int i = 0; i < n; i++) {
        temp = new node();
        cin >> temp->data;
        temp->next = nullptr;

        if (start == nullptr) {
            start = temp;
            p2 = temp;
        } else {
            p2->next = temp;
            p2 = p2->next;
        }
    }

    int x;
    cin >> x;

    for (int i = 0; i < n; i++)
        deleteNode(start, x);

    display();

    return 0;
}
