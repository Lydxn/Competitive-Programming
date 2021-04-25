#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

deque<int> dq1, dq2;
int N, f, b;

bool solve(deque<int> &dq, bool front) {
	if (front) f = b = dq.front(), dq.pop_front();
	else       f = b = dq.back(), dq.pop_back();

	while (!dq.empty()) {
		if (dq.front() == f + 1) ++f, dq.pop_front();
		else if (dq.back() == f + 1) ++f, dq.pop_back();
		else if (dq.front() == b - 1) --b, dq.pop_front();
		else if (dq.back() == b - 1) --b, dq.pop_back();
		else break;
	}
	return dq.empty();
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, x;
	cin >> T;
	for (int _ = 1; _ <= T; _++) {
		cin >> N; dq1.clear(); dq2.clear();
		for (int i = 0; i < N; i++) cin >> x, dq1.push_back(x), dq2.push_back(x);
		cout << "Case #" << _ << ": " << (solve(dq1, true) || solve(dq2, false) ? "yes" : "no") << '\n';
	}
	return 0;
}
