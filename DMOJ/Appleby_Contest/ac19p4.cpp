#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define encode(x, y) (x + 20000) << 16LL | (y + 20000)

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;

int x[2000], y[2000];
gp_hash_table<ll, null_type> pts;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i], pts.insert(encode(x[i], y[i]));

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (pts.find(encode(x[i], y[j])) != pts.end() && pts.find(encode(x[j], y[i])) != pts.end()) {
                ans = max(ans, abs((x[i] - x[j]) * (y[i] - y[j])));
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
