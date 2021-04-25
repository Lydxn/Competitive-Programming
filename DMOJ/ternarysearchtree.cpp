#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int trie[1000][3], key[1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, v;
	cin >> N >> key[0];

	memset(trie, -1, sizeof(trie));
	for (int i = 0, idx = 0; i < N - 1; i++) {
		cin >> v;
		int cur = 0, par = 0, dir = 0;
		while (cur != -1) par = cur, cur = trie[cur][dir = v < key[cur] ? 0 : v > key[cur] ? 2 : 1];
		cout << key[par] << '\n';
		key[trie[par][dir] = ++idx] = v;
	}
	return 0;
}
