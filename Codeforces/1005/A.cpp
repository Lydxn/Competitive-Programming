#include <bits/stdc++.h>

using namespace std;

int a[1000];
vector<int> steps;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] != 1) steps.push_back(a[i]);
    }
    steps.push_back(a[n - 1]);
    
    cout << steps.size() << '\n';
    for (int s : steps) cout << s << ' ';
    return 0;
}
