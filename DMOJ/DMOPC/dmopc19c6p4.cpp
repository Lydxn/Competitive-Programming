#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set v[1000011];
int arr[500001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, Q, op, x, l, r, c;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) v[500000].insert(i);

    while (Q--) {
        cin >> op;
        if (op == 1) {
            cin >> x;
            v[arr[x] + 500000].erase(x);
            v[++arr[x] + 500000].insert(x);
        }
        else if (op == 2) {
            cin >> x;
            v[arr[x] + 500000].erase(x);
            v[--arr[x] + 500000].insert(x);
        }
        else {
            cin >> l >> r >> c; c += 500000;
            cout << v[c].order_of_key(r + 1) - v[c].order_of_key(l) << '\n';
        }
    }
    return 0;
}
