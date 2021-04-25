#include <bits/stdc++.h>

using namespace std;

pair<int, int> exams[5000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, day = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> exams[i].first >> exams[i].second;
    
    sort(exams, exams + n);
    
    for (int i = 0; i < n; i++)
    {
        if (day <= exams[i].second) day = exams[i].second;
        else                        day = exams[i].first;
    }
    
    cout << day << '\n';
    return 0;
}
