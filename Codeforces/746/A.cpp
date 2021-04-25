#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    
    cout << 7 * min(a, min(b / 2, c / 4)) << '\n';
    return 0;
}
