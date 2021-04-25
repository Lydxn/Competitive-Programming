#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ordered_set oset;
int frd[1000001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, X, R, K;
    cin >> N;
    char op;
    
    while (N--)
    {
        cin >> op;
        if (op != 'Q')
        {
            cin >> X >> R;
            if (op == 'M') oset.erase(oset.find({frd[X], X}));
            frd[X] = R;
            oset.insert({R, X});
        }
        else
        {
            cin >> K;
            cout << oset.find_by_order(oset.size() - K)->second << '\n';
        }
    }
}
