#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string x;
    cin >> x;

    for (int i = 0; i < x.size(); i++)
    {
        if (i == 0 && x[i] == '9') continue;
        if (x[i] >= '5') x[i] = 105 - x[i];
    }
    
    cout << x << '\n';
    return 0;
}
