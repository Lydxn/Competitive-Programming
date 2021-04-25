#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    
    int ab = s.find("AB"), ba = s.find("BA");
    cout << ab << ' ' << ba << '\n';
    cout << ((ab != -1 && s.find("BA", ab + 2) != -1) || (ba != -1 && s.find("AB", ba + 2) != -1) ? "YES" : "NO") << '\n';
    return 0;
}
