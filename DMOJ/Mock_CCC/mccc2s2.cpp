#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N; string S; deque<char> ans;
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        if (S[i] > ans[0]) ans.push_back(S[i]);
        else ans.push_front(S[i]);
    }

    for (char c : ans) cout << c;
    cout << '\n';
    return 0;
}
