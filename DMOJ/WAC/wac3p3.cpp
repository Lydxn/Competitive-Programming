#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<string, pair<int, int>> psi;

bool comp(psi& a, psi& b) {
    if (a.first.size() == b.first.size()) return a.second.second < b.second.second;
    else return a.first.size() > b.first.size();
}
psi combo[5];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string S; int M, ans = 0;
    cin >> S >> M;

    for (int i = 0; i < M; i++) {
        cin >> combo[i].first >> combo[i].second.first;
        combo[i].second.second = i;
    }
    sort(combo, combo + M, comp);

    for (int i = 0; i < S.size(); i++) { nxt:;
        for (int j = 0; j < M; j++) {
            if (combo[j].first == S.substr(i, int(combo[j].first.size()))) {
                ans += combo[j].second.first;
                i += combo[j].first.size();
                goto nxt;
            }
        }
    }

    cout << ans + int(S.size()) << '\n';
    return 0;
}
