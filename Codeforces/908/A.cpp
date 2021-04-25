#include <bits/stdc++.h>

using namespace std;

const string check = "aeiou13579";

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) cnt += check.find(s[i]) != string::npos;
    
    cout << cnt << '\n';
    return 0;
}
