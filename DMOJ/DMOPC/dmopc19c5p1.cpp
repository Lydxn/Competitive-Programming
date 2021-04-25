#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_set<string> items;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, T, cnt = 0; string s, r;
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> s, items.insert(s);

    for (int i = 0; i < M; i++) {
        cin >> T; bool flag = false;
        for (int i = 0; i < T; i++) cin >> r, flag |= (items.find(r) == items.end());
        if (!flag) ++cnt;
    }

    cout << cnt << '\n';
    return 0;
}
