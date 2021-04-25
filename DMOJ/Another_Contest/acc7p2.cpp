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

int N, p[5001];
bool vis[5001];

void guess() {
	for (int i = 1; i <= N; i++) cout << p[i] << " \n"[i == N];
	cout.flush();
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	srand(time(0));

	cin >> N;
	for (int i = 1; i <= N; i++) p[i] = i;
	random_shuffle(p + 1, p + N + 1);
	guess();
	while (true) {
		int T, rnd;
		cin >> T;
		if (T == 0) break;
		if (T == -1) assert(false);
		vis[T] = true;
		while (vis[rnd = rand() % N + 1]);
		swap(p[T], p[rnd]); guess();
	}
	return 0;
}
