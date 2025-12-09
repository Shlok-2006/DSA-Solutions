#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> v;
    vector<int> a[26];

    int n = s.size();

    for (int i = 0; i <= n; i++) {
        if (i < n && s[i] == '#')
            v.push_back(i);
        else if (i < n)
            a[s[i] - 'a'].push_back(i);
    }

    for (int i = 0; i < 26; i++) {
        for (auto j : a[i])
            v.push_back(j);
    }

    string ans;
    int j = v[v[0]];

    while (j < n && s[j] != '#') {
        ans += s[j];
        j = v[j];
    }

    cout << ans;

    return 0;
}
