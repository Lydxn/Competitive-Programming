#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100001, MAXP = 168;
int R[MAXN], C[MAXN], rpre[MAXP][MAXN], cpre[MAXP][MAXN], primes[MAXP];
vector<int> rmod[MAXN], cmod[MAXN];

bool is_prime(int N) {
	for (int i = 2; i * i <= N; i++) if (N % i == 0) return false;
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, r, c, ra, ca, rb, cb;
	cin >> N >> Q;

	for (int i = 1000, idx = 0; i >= 2; i--) if (is_prime(i)) primes[idx++] = i;
	for (int i = 1; i <= N; i++) {
		cin >> r;
		for (int j = 0; j < MAXP; j++) {
			rpre[j][i] = rpre[j][i - 1];
			if (r % primes[j] == 0) ++rpre[j][i], rmod[i].push_back(j);
		}
	}
	for (int i = 1; i <= N; i++) {
		cin >> c;
		for (int j = 0; j < MAXP; j++) {
			cpre[j][i] = cpre[j][i - 1];
			if (c % primes[j] == 0) ++cpre[j][i], cmod[i].push_back(j);
		}
	}

	while (Q--) {
		cin >> ra >> ca >> rb >> cb; int ans = -1;
		for (int p : rmod[rb]) {
			if (cpre[p][ca] - cpre[p][ca - 1] == 1 || rpre[p][rb] - rpre[p][ra - 1] == rb - ra + 1 || (rpre[p][ra] - rpre[p][ra - 1] == 1 && cpre[p][cb] - cpre[p][ca - 1])) {
				ans = max(ans, primes[p]);
				break;
			}
		}
		for (int p : cmod[cb]) {
			if (rpre[p][ra] - rpre[p][ra - 1] == 1 || cpre[p][cb] - cpre[p][ca - 1] == cb - ca + 1 || (cpre[p][ca] - cpre[p][ca - 1] == 1 && rpre[p][rb] - rpre[p][ra - 1])) {
				ans = max(ans, primes[p]);
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
