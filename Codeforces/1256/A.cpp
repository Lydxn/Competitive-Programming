#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int q, a, b, n, S;
    cin >> q;
    
    while (q--)
    {
        cin >> a >> b >> n >> S;
        cout << (S % n <= b && 1LL * a * n + b >= S ? "YES" : "NO") << '\n';
    }
    return 0;
}
