#include <bits/stdc++.h>

using namespace std;

int a[2000], psa[2001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ++psa[a[i]];
    }
    
    for (int i = 2000; i > 0; i--) psa[i - 1] += psa[i];
    
    for (int i = 0; i < n; i++) cout << psa[a[i] + 1] + 1 << ' ';
    return 0;
}
