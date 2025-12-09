#include <iostream>
using namespace std;

void solve() {}

struct node {
    int data;
    node *left, *right;
} *root = nullptr;

void insert(int data) {
    node* tempNode = new node();
    tempNode->data = data;
    tempNode->left = nullptr;
    tempNode->right = nullptr;

    if (root == nullptr) {
        root = tempNode;
        return;
    }

    node* current = root;
    node* parent = nullptr;

    while (true) {
        parent = current;

        if (data < parent->data) {
            current = current->left;
            if (current == nullptr) {
                parent->left = tempNode;
                return;
            }
        } else {
            current = current->right;
            if (current == nullptr) {
                parent->right = tempNode;
                return;
            }
        }
    }
}

void preorder(node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    solve();
    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(x);
    }

    preorder(root);
    return 0;
}
