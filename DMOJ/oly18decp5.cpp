#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, X, Y;
	cin >> N >> X >> Y;

	for (int cnt = 1; ; cnt++) {
		int mid = (X + Y) >> 1;
		if (mid > N) Y = mid;
		else if (mid < N) X = mid;
		else {
			cout << cnt << '\n';
			return 0;
		}
	}
	return 0;
}
