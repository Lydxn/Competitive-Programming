#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T, D, P;
    cin >> T >> D >> P;

    cout << ((T < -40) + (D >= 15) + (P > 50) >= 2 ? "YES" : "NO") << '\n';
    return 0;
}
