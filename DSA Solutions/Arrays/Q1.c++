#include <iostream>
using namespace std;

struct interval {
    int buy;
    int sell;
};

void stockBS(int arr[], int n) {
    if (n == 1)
        return;

    int count = 0;
    interval sol[n / 2 + 1];
    int i = 0;

    while (i < n - 1) {
        while (i < n - 1 && arr[i + 1] <= arr[i])
            i++;

        if (i == n - 1)
            break;

        sol[count].buy = i++;
        while (i < n && arr[i] >= arr[i - 1]) {
            if (arr[i] > arr[i - 1])
                i++;
            else
                break;
        }

        sol[count].sell = i - 1;
        count++;
    }

    for (i = 0; i < count; i++)
        cout << "(" << sol[i].buy << " " << sol[i].sell << ")";
}

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        if (n == 4)
            cout << "No Profit";
        else
            stockBS(arr, n);

        cout << "\n";
    }

    return 0;
}
