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

string X[7], Y[7], _, cows[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> X[i] >> _ >> _ >> _ >> _ >> Y[i];

	sort(cows, cows + 8);
	do {
		bool good = true;
		for (int i = 0; i < N; i++) {
			int l = distance(cows, find(cows, cows + 8, X[i]));
			int r = distance(cows, find(cows, cows + 8, Y[i]));
			if (abs(l - r) != 1) good = false;
		}

		if (good) {
			for (int i = 0; i < 8; i++) cout << cows[i] << '\n';
			return 0;
		}
	} while (next_permutation(cows, cows + 8));
	return 0;
}
