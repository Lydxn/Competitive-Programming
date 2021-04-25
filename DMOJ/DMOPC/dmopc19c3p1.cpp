#include <bits/stdc++.h>

using namespace std;

int freq[300000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, a, max_freq = INT_MIN;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a;
        ++freq[a + 100000];
    }

    for (int f : freq) max_freq = max(max_freq, f);
    for (int i = 0; i < 300000; i++)
    {
        if (freq[i] == max_freq) cout << i - 100000 << ' ';
    }
    return 0;
}
