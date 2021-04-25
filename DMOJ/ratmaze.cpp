#include <iostream>

using namespace std;

int maze[500][500], N;

bool solve(int x, int y)
{
	if (x == N - 1 && y == N - 1) return true;
	if (x >= 0 && x < N && y >= 0 && y < N && maze[y][x] == 0)
	{
		maze[y][x] = 1;
		if (solve(x + 1, y) || solve(x, y + 1) || solve(x - 1, y) || solve(x, y - 1)) return true;
	}
	return false;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> maze[i][j];
		}
	}

	cout << (solve(0, 0) ? "yes" : "no") << '\n';
	return 0;
}
