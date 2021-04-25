#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int freq[26];

ll fact(int n)
{
    ll res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

ll solve(int n)
{
    ll res = 1;
    for (int i = 0; i < 26; i++) res *= fact(freq[i]);
    return fact(n) / res;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    string S;
    cin >> N >> K >> S;

    for (int i = 0; i < N; i++)
    {
        if (S[i] >= 'a' && S[i] <= 'z') ++freq[S[i] - 'a'];
    }

    ll ans = 0;
    if (K == 0)
    {
        ans = solve(N);
    }
    else if (K == 1)
    {
        for (int i = 0; i < 26; i++)
        {
            ++freq[i];
            ans += solve(N);
            --freq[i];
        }
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            for (int j = i; j < 26; j++)
            {
                ++freq[i], ++freq[j];
                ans += solve(N);
                --freq[i], --freq[j];
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
