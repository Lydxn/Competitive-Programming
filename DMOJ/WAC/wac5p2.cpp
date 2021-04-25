#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int a[200000];
int mn[200001], mx[200001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, L, e;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) cin >> a[i];

	mn[N] = INT_MAX, mx[N] = INT_MIN;
	for (int i = N - 1; i >= 0; i--) mn[i] = min(mn[i + 1], a[i]), mx[i] = max(mx[i + 1], a[i]);

	while (Q--) {
		cin >> L >> e;
		int mint = L - e, maxt = L + e;

		int l = 0, r = N - 1, mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (mint <= mn[N - mid - 1] && maxt >= mx[N - mid - 1]) l = mid + 1;
			else r = mid - 1;
		}
		cout << l << '\n';
	}
	return 0;
}
