#include <iostream>
using namespace std;

int main() {
    long long i, j, t, H, C, height, Q;
    long long S[100000], E[100000], h[100000];
    long long nc = 0, val = 0, flag = 0, maximum_height = 0;

    cin >> H >> C >> Q;

    for (i = 0; i < C; i++) {
        cin >> h[i] >> S[i] >> E[i];
        if (h[i] > maximum_height)
            maximum_height = h[i];
    }

    for (i = 0; i < Q; i++) {
        cin >> height >> t;

        if (height > maximum_height) {
            cout << "YES\n";
        } else {
            val = 0;
            nc = 0;
            flag = 0;

            for (j = 0; j < C; j++) {
                if (t >= S[j] && t <= E[j]) {
                    nc++;
                    if (height <= h[j]) {
                        cout << "NO\n";
                        flag = 1;
                        break;
                    } else {
                        val++;
                    }
                }
            }

            if (flag == 0) {
                if (nc == val)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }

    return 0;
}
