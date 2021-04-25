#include <bits/stdc++.h>

using namespace std;

namespace Knapsack
{
    template <typename T>
    T small_w(const int N, const int W, const auto& w, const auto& v)
    {
        vector<T> dp(W + 1);
        for (int i = 0; i < N; i++)
        {
            for (int j = W; j >= w[i]; j--) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
        return dp[W];
    }

    template <typename T>
    T small_v(const int N, const int W, const auto& w, const auto& v)
    {
        int V = 0; for (int i = 0; i < N; i++) V += v[i];
        vector<T> dp(V + 1, W + 1);
        dp[0] = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = V; j >= v[i]; j--) dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }

        for (int i = V; i >= 0; i--)
        {
            if (dp[i] <= W) return i;
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int C, M, N, K;
    cin >> C >> M;
    
    vector<int> w(C), v(C);
    for (int i = 0; i < C; i++) {
        cin >> N >> K;
        w[i] = K, v[i] = N;
    }
    
    cout << Knapsack::small_w<int>(C, M, w, v) << '\n';
    return 0;
}
