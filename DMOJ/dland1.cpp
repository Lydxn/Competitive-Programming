#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100000;
int a[MAXN], notdp[MAXN + 1];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, Q, l, r;
    cin >> N >> Q;
    for (int i = 0; i < N; i++) cin >> a[i];
    
    for (int i = 0; i < Q; i++)
    {
        cin >> l >> r;
        ++notdp[l], --notdp[r + 1];
    }
    
    for (int i = 1; i <= N; i++) notdp[i] += notdp[i - 1];
    sort(notdp + 1, notdp + N + 1, greater<int>());
    sort(a, a + N);
    
    ll ans = 0;
    for (int i = 0; i < N; i++) ans += (ll) a[i] * notdp[i + 1];
    
    cout << ans << '\n';
    return 0;
}
