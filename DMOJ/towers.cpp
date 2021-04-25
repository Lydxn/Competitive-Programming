#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int a[1000000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, good = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];

	for (int i = 1; i < N - 1; i++) good += a[i] > a[i - 1] && a[i] < a[i + 1];
	cout << good << '\n';
	return 0;
}
