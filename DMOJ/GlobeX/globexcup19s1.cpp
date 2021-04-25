#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<int, int> freq;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, K, a, cnt = 0;
    cin >> N >> K;
    
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        cout << freq[a] << '\n';
        ++freq[a];
    }
    
    for (auto f : freq) if (f.second) ++cnt;
    
    cout << cnt << '\n';
    return 0;
}
