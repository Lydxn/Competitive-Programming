#include <bits/stdc++.h>
#define double long double

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const double EPS = 1e-7;
double b[1000000];
int N, M, NM;

double getavg(double C) {
	double avg = 0; for (int i = 0; i < NM; i++) avg += min((double) 1, b[i] * C);
	return avg / NM;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	double avg = 0;
	cin >> N >> M; NM = N * M;
	for (int i = 0; i < NM; i++) cin >> b[i], avg += b[i];

	avg /= N * M;
	if (avg + EPS < 0.48) cout << "underexposed\n";
	else if (abs(avg - EPS) > 0.48) cout << "overexposed\n";
	else {
		cout << "correctly exposed\n";
		return 0;
	}

	double l = 0, r = 1000, mid, c;
	while (r - l > EPS) {
		mid = (l + r) / 2, c = getavg(mid);
		if (c + EPS < 0.48) l = mid;
		else if (abs(c - EPS) > 0.48) r = mid;
		else {
			cout << fixed << setprecision(9) << mid << '\n';
			return 0;
		}
	}
	return 0;
}
