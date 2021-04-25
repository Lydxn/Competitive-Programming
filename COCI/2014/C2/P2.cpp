#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_map<string, int> mp;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; string s;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> s, ++mp[s];
	for (int i = 0; i < N - 1; i++) cin >> s, --mp[s];

	for (auto i : mp) {
		if (i.second > 0) {
			cout << i.first << '\n';
			return 0;
		}
	}
}
