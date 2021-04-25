#include <bits/stdc++.h>

using namespace std;

int freq[101];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, a, max_freq;
    cin >> n;
    
    while (n--)
    {
        cin >> a;
        ++freq[a];
    }
    
    for (int f : freq) max_freq = max(max_freq, f);
    cout << max_freq << '\n';
    return 0;
}
