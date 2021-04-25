#include <bits/stdc++.h>

using namespace std;

int a[1000000], pre[1000000], suf[1000000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, Q, x, maxa;
    cin >> N >> Q;
    for (int i = 0; i < N; i++) cin >> a[i];
    
    for (int i = 0, maxa = INT_MIN; i < N; i++)
    {
        pre[i] = a[i] > maxa ? i : pre[i - 1];
        maxa = max(maxa, a[i]);
    }
    
    for (int i = N - 1, maxa = INT_MIN; i >= 0; i--)
    {
        suf[i] = a[i] > maxa ? i : suf[i + 1];
        maxa = max(maxa, a[i]);
    }
    
    while (Q--)
    {
        cin >> x;
        cout << pre[x - 2] + 1 << ' ' << suf[x] + 1 << '\n';
    }
    return 0;
}
