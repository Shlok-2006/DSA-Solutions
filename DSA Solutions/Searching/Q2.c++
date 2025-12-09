#include <iostream>
using namespace std;

void thirdLargest(int arr[], int arr_size) {
    for (int j = 0; j < arr_size; j++) {
        for (int k = j + 1; k < arr_size; k++) {
            if (arr[j] > arr[k]) {
                int temp = arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    thirdLargest(arr, n);
    cout << "The third Largest element is " << arr[n - 3];
    return 0;
}
