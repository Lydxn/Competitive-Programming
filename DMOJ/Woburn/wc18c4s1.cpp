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

int R[100001], par[3][100001], sz[3][100001];

int find(int *P, int v) { return v == P[v] ? v : P[v] = find(P, P[v]); }
void join(int *P, int *S, int u, int v) {
	if ((u = find(P, u)) == (v = find(P, v))) return;
	if (S[u] < S[v]) swap(u, v);
	P[v] = u, S[u] += S[v];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, K, A, B, ans = 0; char ch;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> ch, R[i] = ch == 'P' ? 0 : ch == 'T' ? 1 : 2;
		par[0][i] = par[1][i] = par[2][i] = i;
		sz[0][i] = sz[1][i] = sz[2][i] = 1;
	}
	
	while (M--) {
		cin >> A >> B;
		if (R[A] == R[B]) join(par[R[A]], sz[R[A]], A, B);
	}
	
	while (K--) {
		cin >> A >> B;
		ans += R[A] == R[B] && find(par[R[A]], A) == find(par[R[B]], B);
	}
	cout << ans << '\n';
	return 0;
}
