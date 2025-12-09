#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

void insertAtEnd(node** head_ref, int new_data) {
    node* new_node = new node();
    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    node* last = *head_ref;
    while (last->next != nullptr)
        last = last->next;

    last->next = new_node;
}

int main() {
    node* head = nullptr;
    int n, c, z;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        insertAtEnd(&head, c);
    }

    cin >> z;

    for (int i = 0; i < z; i++)
        head = head->next;

    cout << "Linked List:";
    node* temp = head;
    while (temp != nullptr) {
        cout << "->" << temp->data;
        temp = temp->next;
    }

    return 0;
}
