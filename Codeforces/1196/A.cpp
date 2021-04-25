#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    
    long long a, b, c;
    while (q--)
    {
        cin >> a >> b >> c;
        cout << (a + b + c) / 2 << '\n';
    }
    return 0;
}
