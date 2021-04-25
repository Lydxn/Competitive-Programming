#include <bits/stdc++.h>

using namespace std;

int freq[2460];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, h, m, max_freq = 0;
    cin >> n;
    
    while (n--)
    {
        cin >> h >> m;
        ++freq[h * 100 + m];
    }
    
    for (int f : freq) max_freq = max(max_freq, f);
    cout << max_freq << '\n';
    return 0;
}
