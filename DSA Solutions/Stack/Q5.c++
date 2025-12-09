#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n, k, i;
    cin >> n >> k;

    int sum = 0;
    int arr[n];
    stack<int> st, st2;

    for (i = 0; i < n; i++) {
        cin >> arr[i];
        st.push(arr[i]);
    }

    for (i = 0; i < k; i++) {
        st2.push(arr[i]);
        sum += arr[i];
    }

    int maxs = sum;

    while (k-- > 1) {
        sum -= st2.top();
        st2.pop();

        sum += st.top();
        st.pop();

        if (sum > maxs)
            maxs = sum;
    }

    cout << maxs;
    return 0;
}
