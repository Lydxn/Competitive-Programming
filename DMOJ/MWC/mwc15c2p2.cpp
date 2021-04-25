#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<pair<int, int>> dq;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, H;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> H;
		while (!dq.empty() && dq.back().first <= H) dq.pop_back();
		cout << (dq.empty() ? i : i - dq.back().second) << ' ';
		dq.emplace_back(H, i);
	}
	cout << '\n';
	return 0;
}
