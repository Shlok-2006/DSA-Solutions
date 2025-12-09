#include <iostream>
using namespace std;

void tel() {
    return;
}

struct node {
    int data;
    node* next;
} *head = nullptr;

void create() {
    int n;
    cin >> n;

    node* p1 = new node;
    int m;
    cin >> m;
    p1->data = m;
    head = p1;

    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;
        node* tt = new node;
        tt->data = a;
        p1->next = tt;
        p1 = p1->next;
    }
    p1->next = nullptr;

    int del;
    cin >> del;

    bool found = false;
    node* nn = head;

    while (nn != nullptr) {
        nn = nn->next;
        node* dd = nn;
        int m = del;

        while (m-- > -1) {
            dd = dd->next;
            if (dd == nullptr) {
                nn->next = nullptr;
                found = true;
                break;
            }
        }

        if (found)
            break;
    }

    cout << "Linked List:";
    while (head != nullptr) {
        cout << "->" << head->data;
        head = head->next;
    }
}

int main() {
    create();
    return 0;
}
