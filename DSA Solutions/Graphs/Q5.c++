#include <bits/stdc++.h>
using namespace std;

void solve() {}

int main() {
    solve();

    long long n, m;
    int k;
    cin >> n >> m >> k;

    vector<pair<long long, long long>> adjList[n + 1];

    for (long long i = 0; i < m; ++i) {
        long long a, b, c;
        cin >> a >> b >> c;
        adjList[a].push_back({b, c});
        adjList[b].push_back({a, c});
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 10000000000000LL));
    queue<pair<long long, long long>> q;

    dp[1][0] = 0;
    q.push({0, 1});

    while (!q.empty()) {
        long long from = q.front().first;
        long long now  = q.front().second;
        q.pop();

        bool change = false;

        for (auto to : adjList[now]) {
            if (to.first == from)
                continue;

            for (int i = 0; i <= k; ++i) {
                if (i != k && dp[to.first][i + 1] > dp[now][i]) {
                    dp[to.first][i + 1] = dp[now][i];
                    change = true;
                }

                if (dp[to.first][i] > dp[now][i] + to.second) {
                    dp[to.first][i] = dp[now][i] + to.second;
                    change = true;
                }
            }
        }

        if (change) {
            for (auto to : adjList[now]) {
                q.push({now, to.first});
            }
        }
    }

    for (long long i = 1; i <= n; i++) {
        long long ans = 10000000000000LL;
        for (long long j = 0; j <= k; j++) {
            ans = min(ans, dp[i][j]);
        }
        cout << ans << " ";
    }

    return 0;
}
