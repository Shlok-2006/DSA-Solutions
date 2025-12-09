#include <iostream>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    int* a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        int z = a[i];
        int sum = 0;
        while (z > 0) {
            sum += (z % 10);
            z /= 10;
        }
        arr[i] = sum;
    }

    while (q--) {
        int Q;
        cin >> Q;
        int ans = -1;

        for (int i = Q; i < n; i++) {
            if (a[i] > a[Q - 1] && arr[i] < arr[Q - 1]) {
                ans = i + 1;
                break;
            }
        }
        cout << ans << " ";
    }

    return 0;
}
