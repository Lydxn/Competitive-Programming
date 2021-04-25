#include <bits/stdc++.h>

using namespace std;

int a[100];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, count = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 0; i < n && a[i] <= k; i++, count++);
    for (int i = n - 1; i >= 0 && a[i] <= k; i--, count++);
    
    cout << min(n, count) << '\n';
    return 0;
}
