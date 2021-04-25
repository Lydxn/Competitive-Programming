#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool sieve[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	memset(sieve, true, sizeof(sieve)); sieve[0] = sieve[1] = false;
	for (int i = 2; i * i <= 100000; i++)
		if (sieve[i])
			for (int j = i * i; j <= 100000; j += i) sieve[j] = false;

	int N;
	for (int _ = 0; _ < 5; _++) {
		cin >> N;
		int sum = 0;
		for (int j = 0; j <= N; j++) if (sieve[j]) sum += j;
		cout << sum << '\n';
	}
	return 0;
}
