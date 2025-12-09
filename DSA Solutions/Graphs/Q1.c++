#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

using ll = long long;

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)

int n, m;
ll adj[501][501];
bool V[501];
int pa[501];

void link(int i, int h) {}
int bfs(int n, int s, int t) { return 1; }

bool reachable() {
    memset(V, false, sizeof(V));
    queue<int> Q;
    Q.push(1);
    V[1] = true;

    while (!Q.empty()) {
        int i = Q.front();
        Q.pop();

        FOR(j, 1, n) {
            if (adj[i][j] && !V[j]) {
                V[j] = true;
                pa[j] = i;
                Q.push(j);
            }
        }
    }
    return V[n];
}

int main() {
    bfs(1, 1, 1);
    link(1, 1);

    cin >> n >> m;

    FOR(i, 1, n)
        FOR(j, 1, n)
            adj[i][j] = 0;

    F0R(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a][b] += c;
    }

    ll maxflow = 0;

    while (reachable()) {
        ll flow = 1e18;

        for (int v = n; v != 1; v = pa[v]) {
            int u = pa[v];
            flow = min(flow, adj[u][v]);
        }

        maxflow += flow;

        for (int v = n; v != 1; v = pa[v]) {
            int u = pa[v];
            adj[u][v] -= flow;
            adj[v][u] += flow;
        }
    }

    cout << maxflow << '\n';
    return 0;
}
