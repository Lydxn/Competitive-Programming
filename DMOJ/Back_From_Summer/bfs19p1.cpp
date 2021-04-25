#include <climits>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, min_cute = INT_MAX, min_index, cute, val;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cute = 0;
		for (int j = 0; j < M; j++)
		{
			cin >> val;
			cute += val == 1 || val == 10;
		}

		if (cute < min_cute)
		{
			min_cute = cute;
			min_index = i;
		}
	}

	cout << min_index << '\n';
	return 0;
}
