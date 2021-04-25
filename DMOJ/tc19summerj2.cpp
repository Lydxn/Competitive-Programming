#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, stone, time = 0;
	cin >> N >> M;

	bool is_adj = false;
	while (N--)
	{
		cin >> stone;
		if (stone == 0 && is_adj)
		{
			time++;
			is_adj = false;
		}
		else if (stone == 1) is_adj = true;
	}

	cout << time + is_adj << '\n';
	return 0;
}
