#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_set<string> uset;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string T, S;
	cin >> T >> S;

	int tlen = T.size(), slen = S.size();
	for (int i = 0; i <= tlen - slen; i++) uset.insert(T.substr(i, slen));

	bool flag = false;
	for (int i = 1; i <= slen; i++) if (uset.count(S.substr(i) + S.substr(0, i))) flag = true;
	cout << (flag ? "yes" : "no") << '\n';
	return 0;
}
