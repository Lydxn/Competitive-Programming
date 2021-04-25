#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

string A[] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

struct wtf {
	string s, y, dir;
};

unordered_map<string, vector<wtf>> mp;

void dfs(string S, string Y, int d = 0) {
	if (S == "Elsie") { cout << abs(d) << '\n'; exit(0); }
	for (auto w : mp[S]) {
		int l = find(A, A + 12, Y) - A, r = find(A, A + 12, w.y) - A;
		if (w.dir == "previous" && r >= l) r -= 12;
		if (w.dir == "next" && r <= l) r += 12;
		dfs(w.s, w.y, d + r - l);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; string s, t, x, y, _;
	cin >> N;
	while (N--) {
		cin >> s >> _ >> _ >> x >> y >> _ >> _ >> t;
		mp[t].push_back({s, y, x});
	}

	dfs("Bessie", "Ox");
	return 0;
}
