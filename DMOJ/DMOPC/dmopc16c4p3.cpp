#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

set<pair<int, int>> stalls[101];
int d[100001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, S, Q, s, a, x, k; char op;
    cin >> N >> S;
    for (int i = 1; i <= N; i++) cin >> d[i];

    while (S--) {
        cin >> s >> a;
        stalls[a].emplace(d[s], s);
    }

    cin >> Q;
    while (Q--) {
        cin >> op >> x;
        if (op != 'Q') {
            cin >> k;
            if (op == 'A') stalls[k].emplace(d[x], x);
            else if (op == 'S') stalls[k].erase({d[x], x});
            else {
                for (auto& s : stalls) s.erase({d[x], x});
                d[x] = k;
            }
        }
        else cout << (stalls[x].empty() ? -1 : (*stalls[x].begin()).second) << '\n';
    }
    return 0;
}
