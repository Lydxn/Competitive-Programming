#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<int, int> cntx, cnty;
unordered_map<int, unordered_map<int, bool>> isxy;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, Q, X, Y, a, b, c; char d;
    cin >> N >> Q;

    while (N--) {
        cin >> X >> Y;
        ++cntx[X], ++cnty[Y], isxy[X][Y] = true;
    }

    while (Q--) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            cout << (isxy[b][c] ? "salty" : "bland") << '\n';
        } else if (a == 2) {
            cin >> d >> b;
            cout << (d == 'X' ? cntx[b] : cnty[b]) << '\n';
        }
    }
    return 0;
}
