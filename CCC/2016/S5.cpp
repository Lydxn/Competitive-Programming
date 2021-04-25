#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool S[100000], tmp[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; ll T; char ch;
	cin >> N >> T;
	for (int i = 0; i < N; i++) cin >> ch, S[i] = ch - '0';

	for (int i = 50; i >= 0; i--) {
		ll mask = (1LL << i);
		if (T & mask) {
			for (int j = 0; j < N; j++) tmp[j] = S[(j + mask) % N] ^ S[(j - mask % N + N) % N];
			memcpy(S, tmp, N);
		}
	}

	for (int i = 0; i < N; i++) cout << S[i];
	cout << '\n';
	return 0;
}
