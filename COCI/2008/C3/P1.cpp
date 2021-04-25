#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, mx = 0, mi = -1;
	for (int i = 1; i <= 5; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) cin >> n, sum += n;
		if (mx < sum) mx = sum, mi = i;
	}

	cout << mi << ' ' << mx << '\n';
	return 0;
}
