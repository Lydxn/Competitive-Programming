#include <bits/stdc++.h>

using namespace std;

bool diverse(string s)
{
    sort(s.begin(), s.end());
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] - s[i - 1] != 1) return false;
    }
    return true;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    string s;
    cin >> n;
    
    while (n--)
    {
        cin >> s;
        cout << (diverse(s) ? "Yes" : "No") << '\n';
    }
    return 0;
}
