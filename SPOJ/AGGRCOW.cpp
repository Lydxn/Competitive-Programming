#include <algorithm>
#include <iostream>

using namespace std;

int stalls[100000], N, C;

bool assignable(int dist)
{
	int cows = 1, prev = stalls[0];
	for (int i = 1; i < N; i++)
	{
		if (stalls[i] - prev >= dist)
		{
			prev = stalls[i];
			++cows;
			if (cows == C) return true;
		}
	}
	return false;
}

int binary_search()
{
	int left = 0, right = stalls[N - 1] - stalls[0], mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (assignable(mid)) left = mid + 1;
		else					right = mid;
	}
	return left - 1;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		cin >> N >> C;
		for (int i = 0; i < N; i++) cin >> stalls[i];

		sort(stalls, stalls + N);
		cout << binary_search() << '\n';
	}
	return 0;
}
