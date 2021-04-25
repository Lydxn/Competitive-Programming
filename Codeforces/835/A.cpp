#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int s, v1, v2, t1, t2, p1, p2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    
    p1 = s * v1 + 2 * t1, p2 = s * v2 + 2 * t2;
    cout << (p1 < p2 ? "First" : p1 > p2 ? "Second" : "Friendship") << '\n';
    return 0;
}
