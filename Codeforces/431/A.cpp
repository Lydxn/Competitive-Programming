#include <bits/stdc++.h>

using namespace std;

int a[4];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> s;
    
    int calories = 0;
    for (char c : s)
    {
        calories += a[c - '1'];
    }
    
    cout << calories << '\n';
    return 0;
}
