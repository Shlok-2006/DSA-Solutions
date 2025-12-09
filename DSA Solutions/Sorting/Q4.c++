#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int curr = arr[i];
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > curr) {
                arr[j + 1] = arr[j];
                if (j == 0)
                    arr[j] = curr;
            } else {
                arr[j + 1] = curr;
                break;
            }
        }
        if (i == 2) {
            for (int k = 0; k < n; k++)
                cout << arr[k] << " ";
            cout << endl;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
