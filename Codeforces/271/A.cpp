#include <iostream>

using namespace std;

bool is_distinct(int y)
{
	bool visited[10] = { false };
	while (y)
	{
		if (visited[y % 10]) return false;
		visited[y % 10] = true;
		y /= 10;
	}
	return true;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int y;
	cin >> y;

	while (!is_distinct(++y));
	cout << y << '\n';
	return 0;
}
