#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[3];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> a[0] >> a[1] >> a[2];
    
    sort(a, a + 3);
    
    cout << max(0, a[2] - a[0] - a[1] + 1) << '\n';
    return 0;
}
