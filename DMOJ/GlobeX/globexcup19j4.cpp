#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cards[100000];
map<int, int> m;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, K;
    ll ans = 0;
    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i++)
    {
        cin >> cards[i];
        m[cards[i]]++;
    }
    
    vector<int> a;
    for (auto i : m)
    {
        a.push_back(i.second);
    }
    
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < a[i]; j++)
        {
            if (K == 0) goto end;
            ans += j, --K;
        }
    }
    end:;
    
    cout << ans << '\n';
    return 0;
}
