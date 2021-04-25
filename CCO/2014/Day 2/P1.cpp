#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<pii> good;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, P, A, B, sum = 0, cnt = 1;
	cin >> N >> P;
	for (int i = 1; i <= N; i++) {
		cin >> A >> B;
		if (i == P) sum = A;
		else if (A >= B) good.emplace_back(B, A - B);
	}

	sort(good.begin(), good.end());
	for (auto g : good) {
		if (sum >= g.first) {
			sum += g.second;
			++cnt;
		}
	}

	cout << sum << '\n' << cnt << '\n';
	return 0;
}
