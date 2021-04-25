#include <stdio.h>
#include <string.h>
#pragma GCC optimize "Ofast"

int trie[1000000][26];
char S[1000000];

int main() {
	int T, N;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		memset(trie, -1, sizeof(trie));
		scanf("%d", &N); int ans = 0, cnt = 0;
		while (N--) {
			scanf("%s", S); int len = strlen(S), pos = 0, res = -1;
			for (int j = 0; j < len; j++) {
				int ch = S[j] - 'a';
				if (trie[pos][ch] == -1) {
					if (res == -1) res = j + 1;
					trie[pos][ch] = ++cnt;
				}
				pos = trie[pos][ch];
			}
			ans += res == -1 ? len : res;
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}
