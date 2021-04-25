#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("family.in", "r", stdin);
	freopen("family.out", "w", stdout);

	int N; string A, B, X, Y;
	unordered_map<string, string> mp;
	cin >> N >> A >> B;
	for (int i = 0; i < N; i++)
		cin >> X >> Y, mp[Y] = X;

	vector<string> pa, pb; string ta = A, tb = B;
	while (!ta.empty()) pa.push_back(ta), ta = mp[ta];
	while (!tb.empty()) pb.push_back(tb), tb = mp[tb];
	
	int a = 0, b = 0;
	for (; a < int(pa.size()); a++) {
		auto it = find(pb.begin(), pb.end(), pa[a]);
		if (it != pb.end()) { b = it - pb.begin(); break; }
	}
	
	if (a == int(pa.size())) cout << "NOT RELATED\n";
	else if (a == 1 && b == 1) cout << "SIBLINGS\n";
	else if (a > 1 && b > 1) cout << "COUSINS\n";
	else {
		if (a < b) swap(a, b), swap(A, B);
		cout << B << " is the ";
		for (int i = 0; i < a - 2; i++) cout << "great-";
		if (a > 1 && b == 0) cout << "grand-";
		cout << (b == 0 ? "mother" : "aunt") << " of " << A << '\n';
	}
	return 0;
}
