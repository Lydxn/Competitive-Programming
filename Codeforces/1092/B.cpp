#include <bits/stdc++.h>

using namespace std;

int a[100];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a, a + n);
    
    for (int i = 1; i < n; i += 2) sum += a[i] - a[i - 1];
    cout << sum << '\n';
    return 0;
}
