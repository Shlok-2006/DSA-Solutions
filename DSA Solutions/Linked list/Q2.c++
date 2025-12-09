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

void printList(node* node) {
    while (node != nullptr) {
        cout << "-->" << node->key;
        node = node->next;
    }
}

int count(node* head, int search_for) {
    int cnt = 0;
    node* current = head;
    while (current != nullptr) {
        if (current->key == search_for)
            cnt++;
        current = current->next;
    }
    return cnt;
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

    cout << "Linked list:";
    printList(head);
    cout << "\nCount of " << x << ":" << count(head, x);

    return 0;
}
