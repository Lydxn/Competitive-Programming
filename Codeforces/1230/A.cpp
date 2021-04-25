#include <bits/stdc++.h>

using namespace std;

int a[4];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++) cin >> a[i];
    sort(a, a + 4);
    
    cout << (a[0] + a[1] + a[2] == a[3] || a[0] + a[3] == a[1] + a[2] ? "YES" : "NO") << '\n';
    return 0;
}
