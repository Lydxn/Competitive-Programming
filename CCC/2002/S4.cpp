#include <bits/stdc++.h>

using namespace std;

const int MAXQ = 100;
pair<string, int> person[MAXQ];
int dp[MAXQ + 1], pre[MAXQ + 1];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int M, Q, tm;
    cin >> M >> Q;
    for (int i = 0; i < Q; i++) cin >> person[i].first >> person[i].second;
    
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    
    for (int i = 0; i < Q; i++)
    {
        tm = 0;
        for (int j = i; j < min(i + M, Q + 1); j++)
        {
            tm = max(tm, person[j].second);
            if (dp[i] + tm < dp[j + 1])
            {
                dp[j + 1] = dp[i] + tm;
                pre[j + 1] = i;
            }
        }
    }
    cout << "Total Time: " << dp[Q] << '\n';
    
    vector<int> idxs; int curr = Q;
    while (true)
    {
        idxs.push_back(curr);
        if (curr == 0) break;
        curr = pre[curr];
    }
    
    for (int i = idxs.size() - 1; i > 0; i--)
    {
        for (int j = idxs[i]; j < idxs[i - 1]; j++) cout << person[j].first << ' ';
        cout << '\n';
    }
    return 0;
}
