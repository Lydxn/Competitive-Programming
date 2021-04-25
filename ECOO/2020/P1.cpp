#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_map<string, int> mp = {{"C", 0}, {"C#", 1}, {"D", 2}, {"D#", 3}, {"E", 4}, {"F", 5}, {"F#", 6}, {"G", 7}, {"G#", 8}, {"A", 9}, {"A#", 10}, {"B", 11}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, s1, s2, s3, s4; string n1, n2, n3, n4;
	cin >> T;

	while (T--) {
		cin >> n1 >> n2 >> n3 >> n4;
		s1 = (mp[n2] - mp[n1] + 12) % 12, s2 = (mp[n3] - mp[n2] + 12) % 12, s3 = (mp[n4] - mp[n3] + 12) % 12, s4 = (mp[n1] - mp[n4] + 12) % 12;
		if (s1 == 4 && s2 == 3 && s3 == 3 && s4 == 2) cout << "root\n";
		else if (s1 == 3 && s2 == 3 && s3 == 2 && s4 == 4) cout << "first\n";
		else if (s1 == 3 && s2 == 2 && s3 == 4 && s4 == 3) cout << "second\n";
		else if (s1 == 2 && s2 == 4 && s3 == 3 && s4 == 3) cout << "third\n";
		else cout << "invalid\n";
	}
	return 0;
}
