#include <algorithm>
#include <iostream>

using namespace std;

int unocc[1000], bad[3000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> unocc[i];
	for (int i = 0; i < M; i++) cin >> bad[i];

	sort(bad, bad + M);
	
	int dist, max_dist = 0, max_pos = 0, search;
	for (int i = 0; i < N; i++)
	{
		search = lower_bound(bad, bad + M, unocc[i]) - bad;
		dist = 
			search == 0 ? bad[search] - unocc[i] :
			search > M ? unocc[i] - bad[search - 1] :
			min(bad[search] - unocc[i], unocc[i] - bad[search - 1]);

		if (dist > max_dist)
		{
			max_dist = dist;
			max_pos = unocc[i];
		}
	}

	cout << max_pos << '\n';
	return 0;
}
