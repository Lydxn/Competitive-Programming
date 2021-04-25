#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, dist, moves = 0;
	string curr, comb;
	cin >> n >> curr >> comb;

	for (int i = 0; i < n; i++)
	{
		dist = abs(curr[i] - comb[i]);
		moves += min(dist, 10 - dist);
	}

	cout << moves << '\n';
	return 0;
}
