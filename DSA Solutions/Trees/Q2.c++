#include <iostream>
using namespace std;

int N, K;
double ans, a, b;

int main() {
    cin >> N >> K;

    for (int i = 1; i <= K; i++) {
        a = b = 1.0;

        for (int j = 1; j <= N; j++) {
            a *= (double)i / K;
            b *= (double)(i - 1) / K;
        }

        ans += (a - b) * i;
    }

    cout.setf(ios::fixed);
    cout.precision(6);
    cout << ans << "\n";

    return 0;
}
