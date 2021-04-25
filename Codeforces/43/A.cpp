#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> goals;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    string team, t1, t2;
    cin >> n;
    
    while (n--)
    {
        cin >> team;
        ++goals[team];
        
        if (t1.empty()) t1 = team;
        else if (t2.empty() && team != t1) t2 = team;
    }
    
    cout << (goals[t1] > goals[t2] ? t1 : t2) << '\n';
    return 0;
}
