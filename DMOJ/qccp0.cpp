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

	int N; double T;
	cin >> N;
	while (N--) {
		cin >> T;
		if (T < 34) cout << "Too cold, please try again.\n";
		else if (T <= 35.5) cout << "Take a hot bath.\n";
		else if (T <= 38) cout << "Rest if feeling unwell.\n";
		else if (T <= 39) cout << "Take some medicine.\n";
		else if (T <= 41) cout << "Take a cold bath and some medicine.\n";
		else if (T <= 46.1) cout << "Go to the hospital.\n";
		else if (T <= 50) cout << "Congrats, you have a new world record!\n";
		else cout << "Too hot, please try again.\n";
	}
	return 0;
}
