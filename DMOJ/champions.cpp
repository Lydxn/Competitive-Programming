#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<int, int> v[100000];
int friends[100000], ans[100000];

bool comp(const pair<int, int>& v1, const int v2) { return v1.first < v2; }

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
    int n, k, a, b;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> v[i].first, v[i].second = i;
    
    while (k--) {
        cin >> a >> b; --a, --b;
        if (v[a].first > v[b].first) ++friends[a];
        if (v[b].first > v[a].first) ++friends[b];
    }
    
    sort(v, v + n);
    for (int i = 0; i < n; i++) ans[v[i].second] = max(lower_bound(v, v + n, v[i].first, comp) - v, 0L);
    
    for (int i = 0; i < n; i++) cout << ans[i] - friends[i] << ' ';
	return 0;
}
