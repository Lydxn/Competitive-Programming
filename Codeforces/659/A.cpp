#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;
    
    int ans = ((a + b) % n + n) % n;
    cout << (ans == 0 ? n : ans) << '\n';
    return 0;
}
