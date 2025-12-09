#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n], st[n] = {0};
    int temp = 0;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    st[n - 1] = arr[n - 1];
    temp = arr[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                st[i] = arr[i] ^ st[j];
                break;
            }
        }
        if (st[i] == 0)
            st[i] = arr[i];
        if (st[i] > temp)
            temp = st[i];
    }

    cout << temp;

    return 0;
}
