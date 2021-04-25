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

#define ifc(x) (is_prime[(x) >> 6] & (1 << (((x) >> 1) & 31)))
#define isc(x) (is_prime[(x) >> 6] |= (1 << (((x) >> 1) & 31)))

template <typename T>
std::vector<T> get_primes(T N) {
	std::vector<T> res; std::vector<int> is_prime((N >> 6) + 1);
	for (T i = 3; i * i <= N; i += 2) if (!ifc(i)) for (T j = i * i, k = i << 1; j <= N; j += k) isc(j);
	if (N >= 2) res.push_back(2);
	for (T i = 3; i <= N; i += 2) if (!ifc(i)) res.push_back(i);
	return res;
}

template <typename T>
std::vector<T> get_primes_range(T A, T B) {
	assert(A <= B); std::vector<T> primes = get_primes<T>(std::sqrt(B)), res; std::vector<int> is_prime(((B - A + 1) >> 6) + 1);
	if (B < 2) return res;
	if (A < 3) { res.push_back(2); A = 3; }
	if ((A & 1) == 0) ++A;
	for (int i = 1; i < int(primes.size()); i++) {
		T p = primes[i], j = (A + p - 1) / p * p;
		if ((j & 1) == 0) j += p;
		for (T k = p << 1; j <= B; j += k) if (j != p) isc(j - A);
	}
	for (T i = 0; i <= B - A; i += 2) if (!ifc(i)) res.push_back(A + i);
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i : get_primes_range<int>(N, M))
		cout << i << '\n';
	return 0;
}
