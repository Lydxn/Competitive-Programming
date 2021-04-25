#include <bits/stdc++.h>
 
using namespace std;
 
int a[100];
 
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
 
    int n, m, max_money = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a, a + n);
    
    for (int i = 0; i < m && a[i] < 0; i++) max_money -= a[i];
    
    cout << max_money << '\n';
    return 0;
}
