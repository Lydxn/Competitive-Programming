#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, C, x; string s;
    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        cin >> s >> x;
        cout << s << (x > C ? " will" : " will not") << " advance\n";
    }
    return 0;
}
