#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct glass { 
    int xl, yt, xr, yb, t;
    glass() {}
    glass(int xl, int yt, int xr, int yb, int t) : xl(xl), yt(yt), xr(xr), yb(yb), t(t) {}
};

unordered_map<int, int> indx, indy;
int x[2001], y[2001], valx[2001], valy[2001], diff[2001][2001];
glass g[1000];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, T, xl, yt, xr, yb, t;
    cin >> N >> T;
    
    for (int i = 0; i < N; i++) {
        cin >> xl >> yt >> xr >> yb >> t;
        g[i] = glass(xl, yt, xr, yb, t);
        x[i << 1] = xl, x[i << 1 | 1] = xr, y[i << 1] = yt, y[i << 1 | 1] = yb;
    }
    
    sort(x, x + (N << 1)); sort(y, y + (N << 1));
    for (int i = 0; i < N << 1; i++) valx[i] = x[i], indx[x[i]] = i + 1;
    for (int i = 0; i < N << 1; i++) valy[i] = y[i], indy[y[i]] = i + 1;
    
    for (int i = 0; i < N; i++) {
        xl = indx[g[i].xl], yt = indy[g[i].yt], xr = indx[g[i].xr], yb = indy[g[i].yb], t = g[i].t;
        diff[xl][yt] += t, diff[xl][yb] -= t, diff[xr][yt] -= t, diff[xr][yb] += t;
    }
    
    ll ans = 0;
    for (int i = 1; i < N << 1; i++) {
        for (int j = 1; j < N << 1; j++) {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            if (diff[i][j] >= T) ans += 1LL * (valx[i] - valx[i - 1]) * (valy[j] - valy[j - 1]);
        }
    }
    
    cout << ans << '\n';
    return 0;
}
