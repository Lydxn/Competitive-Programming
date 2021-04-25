#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_map<string, int> mp;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string color;
	for (int _ = 0; _ < 10; _++) {
		while (getline(cin, color)) {
			if (color == "end of box") break;
			++mp[color];
		}

		int ans = 0;
		for (auto i : mp) {
			if (i.first == "red") ans += i.second * 16;
			else ans += (i.second + 6) / 7 * 13;
		}
		cout << ans << '\n';
		mp.clear();
	}
	return 0;
}
