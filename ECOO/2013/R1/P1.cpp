#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int L = 0, S = 0, N; string word;
	cin >> N;
	while (cin >> word) {
		if (word == "TAKE") ++L, ++S, N = N == 999 ? 1 : N + 1;
		else if (word == "SERVE") --S;
		else if (word == "CLOSE") cout << L << ' ' << S << ' ' << N << '\n', L = S = 0;
		else return 0;
	}
}
