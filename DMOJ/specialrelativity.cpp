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

ll C, x[2000], y[2000], px[2000], py[2000], dx[2000], dy[2000];
double T[2000];

double f(int i, int j, double t) {
	double cx = px[j] + dx[j] * t, cy = py[j] + dy[j] * t;
	return sqrt((cx - x[i]) * (cx - x[i]) + (cy - y[i]) * (cy - y[i])) - C * t;
}

double collide(int i, int j) {
	// am i even doing this right?
	// r=px[j]-x[i], s=py[j]-y[i]
	// (r+dx[j]*t)^2+(s+dy[j]*t)^2=C*C*t*t
	// r*r+2*r*dx[j]*t+dx[j]*dx[j]*t*t+s*s+2*s*dy[j]*t+dy[j]*dy[j]*t*t=C*C*t*t
	// (dx[j]*dx[j]+dy[j]*dy[j])*t*t+(2*r*dx[j]+2*s*dy[j])*t+(r*r+s*s)=C*C*t*t
	// (dx[j]*dx[j]+dy[j]*dy[j]-C*C)*t*t+(2*r*dx[j]+2*s*dy[j])*t+(r*r+s*s)=0
	double r = px[j] - x[i], s = py[j] - y[i];
	double a = dx[j] * dx[j] + dy[j] * dy[j] - C * C;
	double b = 2 * (r * dx[j] + s * dy[j]);
	double c = r * r + s * s;
	double d = b * b - 4 * a * c;
	if (d < 0) return -1;
	double s0 = (-b + sqrt(d)) / (2 * a), s1 = (-b - sqrt(d)) / (2 * a);
	if (s0 > s1) swap(s0, s1);
	return s0 >= 0 ? s0 : s1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M; double ans = 0;
	cin >> N >> M >> C;
	for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
	for (int i = 0; i < M; i++) cin >> px[i] >> py[i] >> dx[i] >> dy[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) T[j] = collide(i, j);
		sort(T, T + M);
		for (int j = 0; j < M; j++) ans += T[j] * (2 * j - M + 1);
	}
	cout << fixed << setprecision(10) << ans << '\n';
	return 0;
}