#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s, temp = "";
    cin >> s;

    stack<string> stk;

    for (unsigned int i = 0; i < s.size(); i++) {
        if (s[i] == '/' || s[i] == '\\') {
            if (!temp.empty()) {
                stk.push(temp);
                temp.clear();
            }
        } else {
            temp.push_back(s[i]);
        }
    }

    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }

    return 0;
}
