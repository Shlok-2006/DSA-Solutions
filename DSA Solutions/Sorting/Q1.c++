#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, i, sum = 0;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    for (i = 0; i < n; i++) {
        int z = arr[n - i - 1] - (i + 1);
        sum += abs(z);
    }

    cout << sum;
    return 0;
}
