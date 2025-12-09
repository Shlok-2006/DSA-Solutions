#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

void solve() {}

node* root = nullptr;

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

void inorder(node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    solve();

    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];

    for (int i = 0; i < n; i++)
        insert(array[i]);

    inorder(root);

    return 0;
}
