#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"

using namespace std;

typedef long long ll;

template <typename T>
struct Line
{
    T m, b;
    int id;
    
    T get(T x) { return m * x + b; }
};

template <const int MAXN, typename T>
struct StaticCHT
{
    int ptr, sz;
    Line<T> v[MAXN];
    
    void init() { sz = ptr = 0; }
    
    bool bad(Line<T>& a, Line<T>& b, Line<T>& c) { return (a.b - c.b) * (b.m - a.m) <= (c.m - a.m) * (a.b - b.b); }
    
    void insert(Line<T> x)
    {
        while (ptr + 1 < sz && bad(v[sz - 2], v[sz - 1], x)) --sz;
        v[sz++] = x;
    }
    
    pair<T, int> get(T x)
    {
        ptr = min(ptr, sz);
        while (ptr + 1 < sz && v[ptr].get(x) <= v[ptr + 1].get(x)) ++ptr;
        return { v[ptr].get(x), v[ptr].id };
    }
};

const int MAXN = 100001, MAXK = 201;
int a[MAXN], track[MAXK][MAXN], ans[MAXN];
ll dp[2][MAXN];
StaticCHT<MAXN, ll> cht;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, curr;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    
    for (int i = 1; i <= k; i++)
    {
        cht.init();

        int row = i & 1;
        for (int j = i; j <= n; j++)
        {
            auto temp = cht.get(a[j]);
            dp[row][j] = temp.first, track[i][j] = temp.second;
            cht.insert({ a[j], dp[row ^ 1][j] - 1LL * a[j] * a[j], j });
        }
    }
    
    cout << dp[k & 1][n] << '\n';

    curr = n;
    for (int i = k; i > 0; i--) ans[i] = curr = track[i][curr];
    for (int i = 1; i <= k; i++) cout << ans[i] << ' ';
    return 0;
}
