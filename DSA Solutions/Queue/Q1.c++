#include <iostream>
using namespace std;

#define SIZE 100

void enqueue(int);
void display();

int items[SIZE], front = -1, rear = -1;

int main() {
    int n, data;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        enqueue(data);
        display();
    }

    return 0;
}

void enqueue(int data) {
    if (rear == SIZE - 1) {
        cout << "Queue is Full!!";
    } else {
        if (front == -1)
            front = 0;
        rear++;
        items[rear] = data;
        cout << "Enqueuing " << data << "\n";
    }
}

void display() {
    if (rear == -1) {
        cout << "\nQueue is Empty!!!";
    } else {
        for (int i = front; i <= rear; i++)
            cout << items[i] << " ";
    }
}
