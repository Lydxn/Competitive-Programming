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
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) cin >> s, ++mp[s];
		for (auto j : mp) {
			if (j.second > 1) {
				cout << j.first << '\n';
				goto done;
			}
		}
		cout << "???\n"; done:;
		mp.clear();
	}
	return 0;
}
