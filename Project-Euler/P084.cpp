#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

int sq[40], psq[40], cc[16], ch[16], ccidx, chidx;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	srand(time(0));

	memset(cc, -1, sizeof(cc));
	cc[0] = 0, cc[1] = 10;
	random_shuffle(cc, cc + 16);

	memset(ch, -1, sizeof(ch));
	ch[0] = 0, ch[1] = 10, ch[2] = 11, ch[3] = 24, ch[4] = 39, ch[5] = 5, ch[6] = -2, ch[7] = -2, ch[8] = -3, ch[9] = -4;
	random_shuffle(ch, ch + 16);

	int d = 0, pos = 0;
	for (int i = 0; i < 1000000; i++) {
		int a = rand() % 4 + 1, b = rand() % 4 + 1;
		d = a == b ? d + 1 : 0;
		if (d == 3) pos = 10, d = 0;
		else {
			pos = (pos + a + b) % 40;
			if (pos == 2 || pos == 17 || pos == 33) {
				int nxt = cc[ccidx++ % 16];
				if (nxt != -1) pos = nxt;
			} else if (pos == 7 || pos == 22 || pos == 36) {
				int nxt = ch[chidx++ % 16];
				if (nxt >= 0) pos = nxt;
				else if (nxt == -2) nxt = pos == 7 ? 15 : pos == 22 ? 25 : 5;
				else if (nxt == -3) nxt = pos == 7 ? 12 : pos == 22 ? 28 : 12;
				else if (nxt == -4) pos -= 3;
			} else if (pos == 30) pos = 10;
		}
		++sq[pos];
	}

	for (int i = 0; i < 40; i++) psq[i] = i;
	sort(psq, psq + 40, [&] (int a, int b) { return sq[a] > sq[b]; });

	string ans;
	for (int i = 0; i < 3; i++) ans += psq[i] / 10 + '0', ans += psq[i] % 10 + '0';
	cout << ans << '\n';
	return 0;
}
