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

int A, B, Y1[1001], X1[1001], Y2[1001], X2[1001], dist[1001], vis[1001];

int f(int a, int b) {
	if (a == 0) return min(min(Y1[b], X1[b]), min(A - Y2[b] - 1, B - X2[b] - 1));
	else return max(Y1[a] < Y1[b] ? Y1[b] - Y2[a] : Y1[a] - Y2[b], 0) +
                max(X1[a] < X1[b] ? X1[b] - X2[a] : X1[a] - X2[b], 0) - 1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Y, X;
	cin >> A >> B >> N;
	for (int i = 1; i <= N; i++) cin >> Y1[i] >> X1[i] >> Y2[i] >> X2[i];
	cin >> Y >> X;

	int t = -1;
	for (int i = 1; i <= N; i++)
		if (Y1[i] <= Y && Y <= Y2[i] && X1[i] <= X && X <= X2[i])
			{ t = i; break; }

	memset(dist, 0x3f, sizeof(dist)); dist[0] = 0;
	for (int i = 0; i < N; i++) {
		int mn = 0;
		while (vis[mn]) ++mn;
		for (int j = 0; j <= N; j++)
			if (!vis[j] && dist[j] < dist[mn]) mn = j;
		vis[mn] = true;
		for (int j = 0; j <= N; j++)
			if (!vis[j]) dist[j] = min(dist[j], dist[mn] + f(mn, j));
	}
	cout << dist[t] << '\n';
	return 0;
}
