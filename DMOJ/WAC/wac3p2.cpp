#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int D, H;
    cin >> D;

    while (D--) {
        cin >> H;
        if (H <= 2) {
            cout << "1\n";
            continue;
        }

        ll ans = 0;
        for (ll i = H / 3 - 1; i <= H / 3 + 1; i++) ans = max(ans, i * i * (H - i - i));
        cout << ans << '\n';
    }
    return 0;
}
