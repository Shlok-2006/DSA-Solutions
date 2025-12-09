#include <iostream>
using namespace std;

int check(int s) {
    int n, sum = 0;
    for (n = 1; sum < s; n++) {
        sum += n;
        if (sum == s)
            return 1;
    }
    return -1;
}

int binarySearch(int low, int high, int key) {
    return 1;
}

int main() {
    int n, i, flag = 0;
    cin >> n;
    for (i = 2; i <= n / 2; ++i) {
        if (check(i) == 1) {
            if (check(n - i) == 1) {
                flag = 1;
            }
        }
    }
    binarySearch(1, 1, 1);
    if (flag == 0)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}
