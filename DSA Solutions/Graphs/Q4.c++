#include <iostream>
#include <cstring>
using namespace std;

#define N 200000

int main() {
    static int aa[N], cc[N], dd[N], qq[N];
    int n, i, j, c, d, q, cnt;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> aa[i];
        aa[i]--;
    }

    memset(cc, -1, n * sizeof *cc);

    cnt = 0;
    for (i = 0; i < n; i++) {
        if (cc[i] != -1)
            continue;

        d = 0;
        j = i;

        while (cc[j] == -1) {
            cc[j] = -2;
            d++;
            j = aa[j];
        }

        if (cc[j] == -2) {
            c = cnt++;
            q = 0;
            while (cc[j] == -2) {
                cc[j] = c;
                q++;
                j = aa[j];
            }
            qq[c] = q;
            d -= q;
        } else {
            c = cc[j];
            d += dd[j];
        }

        j = i;
        while (cc[j] == -2) {
            cc[j] = c;
            dd[j] = d--;
            j = aa[j];
        }
    }

    for (i = 0; i < n; i++)
        cout << dd[i] + qq[cc[i]] << " ";
    cout << "\n";

    return 0;
}
