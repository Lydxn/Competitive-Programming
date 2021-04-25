#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool comp(const pair<string,ll> &a, 
              const pair<string,ll> &b) 
{ 
    return (a.second < b.second); 
} 

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    ll K;
    cin >> N >> K;
    
    vector<pair<string, ll>> x(N);
    for (int i = 0; i < N; i++)
    {
        cin >> x[i].first >> x[i].second;
    }
    
    sort(x.begin(), x.end(), comp);
    
    vector<ll> v;
    unordered_set<int> mark;
    for (auto i : x) v.push_back(i.second);

    for (int i = 0; i < N - 1; i++)
    {
        int a = upper_bound(v.begin(), v.end(), v[i] + K) - v.begin();
    //cout << a << '\n';
        if (a <= i + 1) continue;
        for (int j = i; j < a; j++) mark.insert(j);
    }
    
    vector<string> n;
    for (int i = 0; i < N; i++)
    {
        if (!mark.count(i)) n.push_back(x[i].first);
    }
    
    sort(n.begin(), n.end());
    for (auto i : n) cout << i << ' ';
    return 0;
}
