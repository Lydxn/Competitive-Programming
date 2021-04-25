#include <algorithm>
#include <iostream>

using namespace std;

long long dist[186738];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q;
	cin >> N >> Q;

	long long x, y, r;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		dist[i] = x * x + y * y;
	}
	sort(dist, dist + N);

	while (Q--)
	{
		cin >> r;
		cout << upper_bound(dist, dist + N, r * r) - dist << '\n';
	}
	return 0;
}
