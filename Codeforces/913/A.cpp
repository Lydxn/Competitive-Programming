#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    cout << (n > 26 ? m : m % (1 << n)) << '\n';
    return 0;
}
