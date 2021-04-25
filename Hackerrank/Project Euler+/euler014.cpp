#include <cstring>
#include <iostream>
#include <map>

using namespace std;

const int MAXN = 5000000;
int cache[MAXN + 1];

int chain_sz(long long N)
{
	if (N == 1) return 1;
	else if (N <= MAXN && cache[N] != -1) return cache[N];
	else
	{
		int res = 1 + chain_sz(N & 1 ? 3 * N + 1 : N >> 1);
		if (N <= MAXN) cache[N] = res;
		return res;
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	memset(cache, -1, sizeof(cache));
	map<int, int> max_chain;
	max_chain[1] = 1;

	int T, N, curr = 1;
	cin >> T;

	while (T--)
	{
		cin >> N;
		for (; curr <= N; curr++)
		{
			int length = chain_sz(curr);
			if (length >= max_chain.rbegin()->second) max_chain[curr] = length;
		}

		auto best = --max_chain.upper_bound(N);
		cout << best->first << '\n';
	}
	return 0;
}
