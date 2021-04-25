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

/*
IDEA:
	1. sort cubes by x-coordinate in decreasing order
	2. iterate through points and move each cube to its correct location as to form the 'T'
	4. handle the 'star' pattern (a square is covered by 4 cubes) separately
*/

const int OFS = 10;
struct point {
	int x, y;
	point() {}
	point(int x, int y) : x(x), y(y) {}
	bool operator< (point c) { return x > c.x || (x == c.x && y > c.y); }
	bool operator== (point c) { return x == c.x && y == c.y; }
	bool operator!= (point c) { return x != c.x || y != c.y; }
} P[5], par[OFS + OFS + 1][OFS + OFS + 1], dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const point INFP = point(INF, INF);
point bot = point(0, 0);
vector<point> path;
bool vis[OFS + OFS + 1][OFS + OFS + 1];
string ans;

char direction(point p) {
	return p.x == 1 ? 'R' : p.x == -1 ? 'L' : p.y == 1 ? 'U' : 'D';
}

int cube_at(point p) {
	for (int i = 0; i < 5; i++)
		if (P[i].x == p.x && P[i].y == p.y)
			return i;
	return -1;
}

int neighbours(point p) {
	int cnt = 0;
	for (auto d : dir) cnt += cube_at(point(p.x + d.x, p.y + d.y)) != -1;
	return cnt;
}

// move one space in any direction
void slide(point p) {
	bot.x += p.x, bot.y += p.y, ans.push_back(direction(p));
	int at = cube_at(bot);
	if (at != -1) P[at].x += p.x, P[at].y += p.y;
}

// move to any location
void move_to(point p) {
	queue<point> q; q.emplace(bot.x, bot.y);
	memset(vis, false, sizeof(vis)), vis[bot.y + OFS][bot.x + OFS] = true;
	for (int i = 0; i <= OFS + OFS; i++) for (int j = 0; j <= OFS + OFS; j++) par[i][j] = INFP;

	while (!q.empty()) {
		point cv = q.front(); q.pop();
		if (cv.x == p.x && cv.y == p.y) break;

		for (auto d : dir) {
			point nv = point(cv.x + d.x, cv.y + d.y);
			if (-OFS <= nv.x && nv.x <= OFS && -OFS <= nv.y && nv.y <= OFS && cube_at(nv) == -1 && !vis[nv.y + OFS][nv.x + OFS])
				vis[nv.y + OFS][nv.x + OFS] = true, q.push(nv), par[nv.y + OFS][nv.x + OFS] = cv;
		}
	}

	bot.x = p.x, bot.y = p.y; path.clear();
	for (; p != INFP; p = par[p.y + OFS][p.x + OFS])
		path.push_back(p);
	reverse(path.begin(), path.end());

	for (int i = 1; i < int(path.size()); i++)
		ans.push_back(direction(point(path[i].x - path[i - 1].x, path[i].y - path[i - 1].y)));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) cin >> P[i].x >> P[i].y;
	sort(P, P + 5);

	point star = INFP;
	for (int i = -5; i <= 5; i++) {
		for (int j = -5; j <= 5; j++) {
			point p = point(i, j);
			if (neighbours(p) == 4)
				star = p;
		}
	}

	if (star != INFP && star != bot) {
		move_to(point(star.x, star.y + 2)), slide(point(0, -1));

		// find remaining 5th point
		point p5 = INFP;
		for (int i = 0; i < 5; i++)
			if (P[i] != point(star.x, star.y) &&
				P[i] != point(star.x - 1, star.y) &&
				P[i] != point(star.x + 1, star.y) &&
				P[i] != point(star.x, star.y - 1))
					p5 = P[i];

		int p5dir = p5.x > star.x ? 1 : -1;
		move_to(point(p5.x - p5dir, p5.y));
		for (int i = 0, x0diff = 7 - p5dir * p5.x; i < x0diff; i++) slide(point(p5dir, 0));
		move_to(point(7 * p5dir, p5.y + 1));
		for (int i = 0, y0diff = p5.y + 7; i < y0diff; i++) slide(point(0, -1));
		move_to(point(8 * p5dir, -7));
		for (int i = 0, x1diff = 7 - p5dir * star.x; i < x1diff; i++) slide(point(-p5dir, 0));
		move_to(point(star.x, -8));
		for (int i = 0, y1diff = star.y + 5; i < y1diff; i++) slide(point(0, 1));
	} else {
		if (star == point(0, 0))
			slide(point(0, neighbours(point(0, 2)) > 1 ? -1 : 1));

		vector<point> order = {{9, 9}, {8, 9}, {7, 9}, {8, 8}, {8, 7}};
		for (int i = 0; i < 5; i++) {
			move_to(point(P[i].x - 1, P[i].y));
			for (int j = 0, xdiff = order[i].x - P[i].x; j < xdiff; j++) slide(point(1, 0));

			move_to(point(P[i].x, P[i].y - 1));
			for (int j = 0, ydiff = order[i].y - P[i].y; j < ydiff; j++) slide(point(0, 1));
		}
	}

	cout << ans << '\n';
	return 0;
}
