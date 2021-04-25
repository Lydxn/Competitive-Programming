#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

char S[500001];
vector<int> L;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> S;
	int sz = strlen(S), ans = 0;
	int cntl = 0, cnts = 0;
	for (int i = 0; i < sz; i++) cntl += S[i] == 'L', cnts += S[i] == 'S';
	for (int i = cntl; i < sz; i++)
		if (S[i] == 'L') L.push_back(i);
	for (int i = 0; i < cntl; i++)
		if (S[i] == 'S' && !L.empty()) swap(S[i], S[L.back()]), L.pop_back(), ++ans;
	for (int i = 0; i < cntl; i++)
		if (S[i] == 'M' && !L.empty()) swap(S[i], S[L.back()]), L.pop_back(), ++ans;
	for (int i = sz - 1; i >= sz - cnts; i--) ans += S[i] != 'S';
	cout << ans << '\n';
	return 0;
}