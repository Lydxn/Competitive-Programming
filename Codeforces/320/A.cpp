#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string n;
    cin >> n;
    
    bool is14 = true;
    for (char c : n) if (c != '1' && c != '4') is14 = false;
    
    cout << (is14 && n[0] == '1' && n.find("444") == string::npos ? "YES" : "NO") << '\n';
    return 0;
}
