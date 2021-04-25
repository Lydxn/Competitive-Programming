#include <algorithm>
#include <bitset>
#include <iostream>

#define scan(x) do{while((_n=getchar_unlocked())<45);if(_n-45)x=_n;else x=getchar_unlocked();for(x-=48;47<(_=getchar_unlocked());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;

typedef long long ll;

using namespace std;

const int MAXN = 100001, MAXR = 5001;

struct node
{
	bitset<MAXR> val;
	ll lazy;
};

ll a[MAXN], K, bases[] = { 2, 3, 5, 7, 11 };
node tree[3 * MAXN];
bitset<MAXR> primes;
int N, Q, oper, l, r, v;

ll mul_mod(ll a, ll b, ll m)
{
	ll res = 0;
	while (b)
	{
		if (b & 1)
		{
			res += a;
			if (res >= m) res -= m;
		}

		a <<= 1;
		if (a >= m) a -= m;
		b >>= 1;
	}
	return res;
}

ll pow_mod(ll a, ll b, ll m)
{
	ll res = 1;
	while (b)
	{
		if (b & 1) res = mul_mod(res, a, m);
		a = mul_mod(a, a, m);
		b >>= 1;
	}
	return res;
}

bool miller_rabin(ll a, ll s, ll d, ll n)
{
	ll pm = pow_mod(a, d, n);
	if (a >= n - 1 || pm == 1 || pm == n - 1) return false;

	while (s--)
	{
		pm = mul_mod(pm, pm, n);
		if (pm == n - 1) return false;
	}
	return true;
}

bool is_prime(ll N)
{
	if (N < 2) return false;
	if (N == 2 || N == 3 || N == 5 || N == 7 || N == 11) return true;
	if (N % 2 == 0 || N % 3 == 0 || N % 5 == 0 || N % 7 == 0 || N % 11 == 0) return false;

	ll s = -1, d = N - 1;
	while ((d & 1) == 0)
	{
		d >>= 1;
		++s;
	}

	for (ll b : bases)
	{
		if (miller_rabin(b, s, d, N)) return false;
	}
	return true;
}

void propogate(int idx, int s, int e)
{
	if (tree[idx].lazy != 0)
	{
		if (tree[idx].lazy > 0) tree[idx].val <<= tree[idx].lazy;
		else if (tree[idx].lazy < 0) tree[idx].val >>= -tree[idx].lazy;

		if (s != e)
		{
			tree[idx << 1].lazy += tree[idx].lazy;
			tree[idx << 1 | 1].lazy += tree[idx].lazy;
		}
		tree[idx].lazy = 0;
	}
}

void build(int idx, int s, int e)
{
	if (s == e) tree[idx].val.set(a[s] - K);
	else
	{
		int mid = (s + e) >> 1;
		build(idx << 1, s, mid);
		build(idx << 1 | 1, mid + 1, e);
		tree[idx].val = tree[idx << 1].val | tree[idx << 1 | 1].val;
	}
}

void update(int idx, int s, int e, int l, int r, int v) {
	propogate(idx, s, e);
	if (s > r || e < l) return;
	if (s >= l && e <= r)
	{
		tree[idx].lazy = v;
		propogate(idx, s, e);
	}
	else
	{
		int mid = (s + e) >> 1;
		update(idx << 1, s, mid, l, r, v);
		update(idx << 1 | 1, mid + 1, e, l, r, v);
		tree[idx].val = tree[idx << 1].val | tree[idx << 1 | 1].val;
	}
}

bitset<MAXR> query(int idx, int s, int e, int l, int r) {
	propogate(idx, s, e);
	if (s > r || e < l)   return bitset<MAXR>();
	if (s >= l && e <= r) return tree[idx].val;
	else
	{
		int mid = (s + e) >> 1;
		return query(idx << 1, s, mid, l, r) | query(idx << 1 | 1, mid + 1, e, l, r);
	}
}

int main()
{
	scan(N); scan(Q); scan(K);

	for (int i = 1; i <= N; i++) scan(a[i]);
	for (int i = 0; i < MAXR; i++)
	{
		if (is_prime(i + K)) primes.set(i);
	}

	build(1, 1, N);
	while (Q--)
	{
		scan(oper); scan(l); scan(r);
		if (oper == 1)
		{
			bitset<MAXR> res = query(1, 1, N, l, r);
			res &= primes;

			for (int i = MAXR - 1; i >= 0; i--)
			{
				if (res.test(i))
				{
					cout << i + K << '\n';
					goto next;
				}
			}
			cout << -1 << '\n';
		}
		else
		{
			scan(v);
			update(1, 1, N, l, r, v);
		}
	next:;
	}
	return 0;
}
