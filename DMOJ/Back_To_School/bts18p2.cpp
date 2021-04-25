#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int freq[26][1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S; int Q, l, r; char c;
	getline(cin, S); cin >> Q;

	for (int i = 0; i < int(S.size()); i++) {
		for (int j = 0; j < 26; j++) freq[j][i + 1] = freq[j][i] + (S[i] == char(j + 97));
	}

	while (Q--) {
		cin >> l >> r >> c;
		cout << freq[c - 97][r] - freq[c - 97][l - 1] << '\n';
	}
	return 0;
}
