#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    
    cout << (a == b ? -1 : (int) max(a.size(), b.size())) << '\n';
    return 0;
}
