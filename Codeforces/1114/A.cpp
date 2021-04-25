#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    
    cout << (x <= a && y <= a + b - x && z <= a + b + c - x - y ? "YES" : "NO") << '\n';
    return 0;
}
