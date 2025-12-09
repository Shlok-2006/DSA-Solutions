#include <iostream>
using namespace std;

struct node {
    int key;
    node* next;
};

void push(node** head_ref, int new_key) {
    node* new_node = new node();
    new_node->key = new_key;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

bool search(node* head, int x) {
    node* current = head;
    while (current != nullptr) {
        if (current->key == x)
            return true;
        current = current->next;
    }
    return false;
}

int main() {
    node* head = nullptr;
    int x, n, t;

    cin >> n;
    while (n--) {
        cin >> t;
        push(&head, t);
    }

    cin >> x;
    search(head, x) ? cout << "Yes" : cout << "No";

    return 0;
}
