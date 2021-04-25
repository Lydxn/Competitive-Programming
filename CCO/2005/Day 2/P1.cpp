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

bool is_prime(int x) {
	if (x <= 1) return false;
	if (x <= 3) return true;
	if (x % 2 == 0 || x % 3 == 0) return false;

	for (int i = 5; i * i <= x; i += 6)
		if (x % i == 0 || x % (i + 2) == 0)
			return false;
	return true;
}

int arr[10001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];

		for (int i = 2; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j < i; j++) sum += arr[j];
			for (int j = i; j <= n; j++) {
				sum += arr[j] - arr[j - i];
				if (is_prime(sum)) {
					cout << "Shortest primed subsequence is length " << i << ":";
					for (int k = j - i + 1; k <= j; k++)
						cout << " " << arr[k];
					cout << '\n';
					goto done;
				}
			}
		}
		cout << "This sequence is anti-primed.\n";
		done:;
	}
	return 0;
}
