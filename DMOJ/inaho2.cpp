#include <bits/stdc++.h>

using namespace std;

int N, Q, op, x, l[10], a[10], b[10], pref[11], BIT[10000000];
short arr[10000000];

void update(int dim, int pos, int val)
{
    if (dim == N) BIT[pos] += val;
    else for (int i = a[dim]; i <= l[dim]; i += i & -i) update(dim + 1, pos + (i - 1) * pref[dim], val);
}

int query(int dim, int pos)
{
    if (dim == N) return BIT[pos];
    int res = 0;
    for (int i = b[dim]; i > 0; i -= i & -i) res += query(dim + 1, pos + (i - 1) * pref[dim]);
    for (int i = a[dim] - 1; i > 0; i -= i & -i) res -= query(dim + 1, pos + (i - 1) * pref[dim]);
    return res;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 0; i < N; i++) cin >> l[i];
    pref[0] = 1; for (int i = 0; i < N; i++) pref[i + 1] = pref[i] * l[i];
    
    while (Q--)
    {
        cin >> op;
        if (op == 1)
        {
            for (int i = 0; i < N; i++) cin >> a[i];
            cin >> x;
            
            int pos = 0;
            for (int i = 0; i < N; i++) pos += (a[i] - 1) * pref[i];
            update(0, 0, x - arr[pos]);
            arr[pos] = x;
        }
        else
        {
            for (int i = 0; i < N; i++) cin >> a[i];
            for (int i = 0; i < N; i++) cin >> b[i];
            cout << query(0, 0) << '\n';
        }
    }
}
