#include <bits/stdc++.h>

using namespace std;

unordered_map<string, vector<string>> adj;
unordered_map<string, bool> vis;

bool dfs(string s, string e) {
	if (s == e) return true;
	vis[s] = true;

	bool can = false;
	for (const auto& i : adj[s]) {
		if (!vis[i]) can |= dfs(i, e);
	}
	return can;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string url, page, link, u1, u2;
	for (int i = 0; i < n; i++) {
		cin >> url;
		while (true) {
			getline(cin, page);
			if (page == "</HTML>") break;

			for (int j = 0; j < int(page.size()) - 9; j++) {
				if (page.substr(j, 9) == "<A HREF=\"") {
					link = page.substr(j + 9, page.find("\"", j + 9) - j - 9);
					adj[url].push_back(link);
					cout << "Link from " << url << " to " << link << '\n';
				}
			}
		}
	}

	while (true) {
		getline(cin, u1);
		if (u1 == "The End") break;
		getline(cin, u2);

		vis.clear();
		cout << (dfs(u1, u2) ? "Can" : "Can't") << " surf from " << u1 << " to " << u2 << ".\n";
	}
	return 0;
}
