#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++)
        cin >> array[i];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    for (int j = 0; j < n; j += 2) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
        cout << array[j] << " " << array[j + 1] << " ";
    }

    return 0;
}
