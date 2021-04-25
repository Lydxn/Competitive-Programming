#include <bits/stdc++.h>

using namespace std;

int a[500];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, res = 0, temp;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 1; i < n; i++)
    {
        int temp = k - a[i] - a[i - 1];
        if (temp > 0) a[i] += temp, res += temp;
    }
    
    cout << res << '\n';
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    return 0;
}
