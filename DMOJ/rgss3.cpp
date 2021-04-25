#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; string S, T;
	cin >> N;

	while (N--) {
		cin >> S >> T; int diff = T.size() - S.size();
		for (int i = 0; i < diff; i++) {
			if (T.back() == 'A') T.pop_back();
			else T.pop_back(), reverse(T.begin(), T.end());
		}
		cout << (S == T ? "YES" : "NO") << '\n';
	}
	return 0;
}
