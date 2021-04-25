#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S[50]; int len = 0;
	while (cin >> S[len++]);
	for (int i = 0; i < len - 1; i++) cout << S[i] << (isupper(S[i + 1][0]) ? "." : "") << (i == len - 2 ? "." : " ");
	cout << '\n';
	return 0;
}
