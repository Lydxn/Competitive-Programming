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

int A[4], S[4], O[4];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> A[i] >> S[i] >> O[i];

		int lcm = 1;
		for (int i = 0; i < N; i++)
			lcm = lcm * (A[i] + S[i]) / __gcd(lcm, A[i] + S[i]);

		for (int i = 0; i < lcm; i++) {
			bool found = true;
			for (int j = 0; j < N; j++)
				found &= (i + O[j]) % (A[j] + S[j]) >= A[j];

			if (found) {
				cout << i << '\n';
				goto done;
			}
		}
		cout << "Foxen are too powerful\n";
		done:;
	}
	return 0;
}
