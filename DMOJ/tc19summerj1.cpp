#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, min_close, min_dist = INT_MAX, dist;
	cin >> N >> M;

	while (N)
	{
		dist = abs(M - N);
		if (dist < min_dist)
		{
			min_dist = dist;
			min_close = N;
		}
		N >>= 1;
	}
	
	cout << min_close << '\n';
	return 0;
}
