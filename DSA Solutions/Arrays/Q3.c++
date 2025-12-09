#include <iostream>
using namespace std;

int main() {
    int rows;
    cin >> rows;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == rows)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }

    return 0;
}
