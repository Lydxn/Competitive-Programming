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

char grid[3000][1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, ptr = 1500; string S;
	cin >> N >> S;
	memset(grid, '.', sizeof(grid));
	for (int i = 0; i < N; i++) {
		if (S[i] == '^') grid[ptr--][i] = '/';
		else if (S[i] == 'v') grid[++ptr][i] = '\\';
		else grid[ptr][i] = '_';
	}
	
	for (int i = 0; i < 3000; i++) {
		bool flag = false;
		for (int j = 0; j < N; j++) flag |= grid[i][j] != '.';
		if (flag) {
			for (int j = 0; j < N; j++) cout << grid[i][j];
			cout << '\n';
		}
	}
	return 0;
}
