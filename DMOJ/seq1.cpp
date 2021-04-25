#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;

ull powmod(ull a, ull b) {
	ull res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		b >>= 1, a = a * a % MOD;
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ull N;
	cin >> N;
	cout << (powmod(2, N + 3) - 5 + MOD) % MOD << '\n';
	return 0;
}
