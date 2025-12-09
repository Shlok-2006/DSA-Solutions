#include <iostream>
using namespace std;

#define N 100000
#define M 200000

struct L {
    L* next;
    int j;
} *aa[N];

L* new_L(int j) {
    static L l91[M + 1 + M];
    static L* l = l91;

    l->j = j;
    return l++;
}

void link(int i, int j) {
    L* l = new_L(j);
    l->next = aa[i];
    aa[i] = l;
}

void hierholzer(L* e) {
    L* f = e->next;
    L* l;
    int i = e->j;

    while ((l = aa[i])) {
        aa[i] = l->next;
        e = e->next = new_L(l->j);
        i = l->j;
    }
    e->next = f;
}

int main() {
    static int din[N], dout[N];
    L *e_, *e;
    int n, m, h, i, j;

    cin >> n >> m;

    for (h = 0; h < m; h++) {
        cin >> i >> j;
        i--, j--;
        link(i, j);
        dout[i]++;
        din[j]++;
    }

    if (dout[0] - din[0] != 1 || din[n - 1] - dout[n - 1] != 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (i = 1; i < n - 1; i++) {
        if (dout[i] != din[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    e_ = new_L(0);
    m++;
    hierholzer(e_);

    for (e = e_; e; e = e->next) {
        hierholzer(e);
        m--;
    }

    if (m != 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (e = e_; e; e = e->next) {
        cout << e->j + 1 << " ";
    }
    cout << "\n";

    return 0;
}
