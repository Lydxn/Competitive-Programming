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

bool sv[16001];
vector<int> primes;
int ans[8001], aidx;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	memset(sv, true, sizeof(sv)); sv[0] = false;
	for (int i = 2; i * i <= 16000; i++)
		if (sv[i])
			for (int j = i * i; j <= 16000; j += i)
				sv[j] = false;

	int N;
	while (cin >> N) {
		if (N == -1) break;
		aidx = 0;
		for (int i = 1; i <= N / 2; i++)
			if (sv[i] && sv[N - i])
			    ans[aidx++] = i;
		for (int i = 0; i < aidx; i++) cout << ans[i] << ' ' << N - ans[i] << '\n';
		cout << '\n';
	}
	return 0;
}
