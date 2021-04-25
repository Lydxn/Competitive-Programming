#include <bits/stdc++.h>

using namespace std;

unordered_set<int> seen;
vector<int> team;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k, a;
    cin >> n >> k;
    
    for (int i = 1; i <= n && team.size() < k; i++)
    {
        cin >> a;
        if (seen.find(a) == seen.end()) team.push_back(i);
        seen.insert(a);
    }
    
    if (team.size() != k) cout << "NO\n";
    else
    {
        cout << "YES\n";
        for (int i : team) cout << i << ' ';
    }
    return 0;
}
