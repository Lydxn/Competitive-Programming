#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_map<string, int> mp;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, mx = 0, rem; string S;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> S, ++mp[S];

	for (auto i : mp) mx = max(mx, i.second);
	rem = N - mx;
	cout << min(mx, rem + 1) + rem << '\n';
	return 0;
}
