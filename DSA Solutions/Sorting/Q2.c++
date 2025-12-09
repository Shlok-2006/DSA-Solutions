#include <iostream>
#include <algorithm>
using namespace std;

int computeLongestSubarray(int arr[], int k, int n) {
    int maxLength = 1;
    for (int i = 0; i < n; i++) {
        int minOfSub = arr[i];
        int maxOfSub = arr[i];
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > maxOfSub)
                maxOfSub = arr[j];
            if (arr[j] < minOfSub)
                minOfSub = arr[j];
            if (maxOfSub - minOfSub <= k) {
                int currLength = j - i + 1;
                if (maxLength < currLength)
                    maxLength = currLength;
            }
        }
    }
    return maxLength;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k = 1;
    sort(arr, arr + n);

    int maxLength = computeLongestSubarray(arr, k, n);
    cout << maxLength;

    return 0;
}
