#include <bits/stdc++.h>

#define get(x, i) (((x) >> i) & 1)
#define pairs(x) ((((ll) x) * ((x) - 1)) >> 1)

using namespace std;

typedef long long ll;

template <const int N, typename T>
struct BIT
{
    T bit[N + 1];
    
    void init() { memset(bit, 0, sizeof(bit)); }
    
    void init(const auto& a, const int sz)
    {
        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= sz; i++)
        {
            bit[i] += a[i];
            int idx = i + (i & -i);
            if (idx <= sz) bit[idx] += bit[i];
        }
    }
    
    void update(int i, const T x)
    {
        for (; i <= N; i += i & -i) bit[i] += x;
    }
    
    T query(int i)
    {
        T res = 0;
        for (; i > 0; i -= i & -i) res += bit[i];
        return res;
    }
    
    T query(const int l, const int r)
    {
        return query(r) - query(l - 1);
    }
};

const int MAXN = 100001, BITS = 27;
int arr[MAXN];
BIT<MAXN, int> bit[BITS];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    ll N, Q, op, a, b, qu, len, ans;
    cin >> N >> Q;
    
    for (int i = 0; i < BITS; i++) bit[i].init();
    
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < BITS; j++)
        {
            if (get(arr[i], j)) bit[j].update(i, 1);
        }
    }
    
    while (Q--)
    {
        cin >> op >> a >> b;
        
        ans = 0, len = b - a + 1;
        switch (op)
        {
            case 1:
                for (int i = 0; i < BITS; i++)
                {
                    if (get(arr[a], i))     bit[i].update(a, -1);
                    if (get(b, i)) bit[i].update(a, 1);
                }
                arr[a] = b;
                break;
            case 2:
                for (int i = 0; i < BITS; i++)
                {
                    qu = bit[i].query(a, b);
                    ans += (pairs(len) - pairs(len - qu)) << i;
                }
                cout << ans << '\n';
                break;
            case 3:
                for (int i = 0; i < BITS; i++)
                {
                    qu = bit[i].query(a, b);
                    ans += pairs(qu) << i;
                }
                cout << ans << '\n';
                break;
            case 4:
                for (int i = 0; i < BITS; i++)
                {
                    qu = bit[i].query(a, b);
                    ans += (qu * (len - qu)) << i;
                }
                cout << ans << '\n';
                break;
        }
    }
    return 0;
}
