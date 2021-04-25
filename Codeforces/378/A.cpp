#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, diff, win = 0, draw = 0, loss = 0;
    cin >> a >> b;
    
    for (int i = 1; i <= 6; i++)
    {
        diff = abs(a - i) - abs(b - i);
        if      (diff < 0) ++win;
        else if (diff > 0) ++loss;
        else               ++draw;
    }
    
    cout << win << ' ' << draw << ' ' << loss << '\n';
    return 0;
},
