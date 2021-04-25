#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S; int K;
	cin >> S >> K;

	for (int i = 0, cnt = 0; i < int(S.size()); i++) {
		cnt = S[i] == 'S' ? cnt + 1 : 0;
		if (cnt >= K) {
			cout << "Spamming\n";
			return 0;
		}
	}

	cout << "All good\n";
	return 0;
}
