#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    x = 1;
    y = 0;

    if (0 == b) return a;

    ll new_x = 0;
    ll new_y = 1;
    ll new_r = b;
    ll r = a;
    ll quotient, tmp;
    while (new_r) {
        quotient = r / new_r;

        tmp = r;
        r = new_r;
        new_r = tmp - quotient * new_r;

        tmp = x;
        x = new_x;
        new_x = tmp - quotient * new_x;

        tmp = y;
        y = new_y;
        new_y = tmp - quotient * new_y;
    }
    return r;
}

ll linear_congruence(ll a, ll b, ll n) {
    ll x, y;
    ll d = exgcd(a, n, x, y);
    if (b % d)
        return false;
    ll x0 = x * (b / d) % n;
    return x0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll N, M, v, ans = 0;
	cin >> N >> M;

	vector<ll> vec;
	while (N--) {
		cin >> v;
		vec.push_back(linear_congruence(2654435761, v, 1LL << 32));
	}

	sort(vec.begin(), vec.end(), greater<ll>());
	for (int i = 0; i < M; i++) ans += vec[i];
	cout << ans << '\n';
	return 0;
}
