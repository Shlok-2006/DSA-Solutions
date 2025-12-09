#include <iostream>
using namespace std;

int main() {
    int num, i, count = 0;
    cin >> num;

    int a[100001], stck[100001];
    int top = -1;

    for (i = 0; i < num; i++) {
        cin >> a[i];

        while (top != -1 && stck[top] < a[i]) {
            top--;
            count++;
        }

        if (top != -1)
            count++;

        stck[++top] = a[i];
    }

    cout << count;

    return 0;
}
