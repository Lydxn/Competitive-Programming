#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; string prev = "";
	while (true) {
		cin >> N;
		if (N == 99999) break;
		int s = N / 1000 % 10 + N / 10000;
		string cur = s == 0 ? prev : s % 2 ? "left" : "right";
		cout << cur << ' ' << N % 1000 << '\n';
		prev = cur;
	}
	return 0;
}