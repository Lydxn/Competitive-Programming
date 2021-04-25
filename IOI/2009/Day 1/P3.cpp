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

int solved[2000][2000], diff[2000];
struct rank {
	int score, tasks, id;
	bool operator< (rank &r) {
		return score > r.score || (score == r.score && tasks > r.tasks) || (score == r.score && tasks == r.tasks && id < r.id);
	}
} r[2000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, T, P;
	cin >> N >> T >> P;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < T; j++)
			cin >> solved[i][j], diff[j] += !solved[i][j];

	for (int i = 0; i < N; i++) {
		int score = 0, tasks = 0, id = i;
		for (int j = 0; j < T; j++)
			if (solved[i][j])
				score += diff[j], ++tasks;
		r[i] = {score, tasks, id};
	}

	sort(r, r + N);
	for (int i = 0; i < N; i++) {
		if (r[i].id == P - 1) {
			cout << r[i].score << ' ' << i + 1 << '\n';
			break;
		}
	}
	return 0;
}
