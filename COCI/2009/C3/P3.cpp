#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_map<int, int> freq, idx;
vector<pair<pii, int>> v;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, C;
	cin >> N >> C;
	for (int i = 0; i < N; i++) cin >> C, ++freq[C], idx[C] = min(idx[C], i - 1000);

	for (auto i : freq) v.push_back({{i.second, -idx[i.first]}, i.first});
	sort(v.begin(), v.end(), greater<pair<pii, int>>());

	for (auto i : v)
		for (int j = 0; j < i.first.first; j++) cout << i.second << ' ';
	cout << '\n';
	return 0;
}
