#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int H, V; ll ans = 0;
    cin >> H >> V;

    for (int x = 1; x < V; x++) {
        for (int y = 0; y < H; y++) {
            for (int dx = y / __gcd(x, y), dy = x / __gcd(x, y), cx = x + dx, cy = y + dy; cx < V && cy < H; cx += dx, cy += dy) {
                ans += (V - cx) * (H - cy);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
