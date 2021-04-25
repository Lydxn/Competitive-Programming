#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<string, bool> m;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, cnt = 0; string s;
    cin >> N >> M;

    while (N--) {
        cin >> s;
        m[s] = true;
    }

    while (M--) {
        cin >> s;
        if (m[s]) ++cnt, m.erase(s);
    }

    cout << cnt << '\n';
    return 0;
}
