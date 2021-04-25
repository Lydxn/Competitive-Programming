#include <bits/stdc++.h>

using namespace std;

int perm[10], mp[256];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n; string a, b, c, s;
	cin >> n;

	while (n--) {
		cin >> a >> b >> c;
		for (int i = 0; i <= 9; i++) perm[i] = i;

		s = a + b + c;
		sort(s.begin(), s.end());
		s.erase(unique(s.begin(), s.end()), s.end());

		do {
			for (int i = 0; i < int(s.size()); i++) mp[s[i]] = perm[i];
			if (mp[a[0]] == 0 || mp[b[0]] == 0 || mp[c[0]] == 0) continue;

			__int128 a0 = 0, b0 = 0, c0 = 0;
			for (char& ch : a) a0 = a0 * 10 + mp[ch];
			for (char& ch : b) b0 = b0 * 10 + mp[ch];
			for (char& ch : c) c0 = c0 * 10 + mp[ch];

			if (a0 + b0 == c0) {
				for (char& ch : a) cout << mp[ch];
				cout << '\n';
				for (char& ch : b) cout << mp[ch];
				cout << '\n';
				for (char& ch : c) cout << mp[ch];
				cout << '\n';
				break;
			}
		} while (next_permutation(perm, perm + 10));
	}
	return 0;
}
