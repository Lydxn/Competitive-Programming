#include <algorithm>
#include <iostream>

using namespace std;

pair<int, int> dragons[1000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int s, n, x, y;
	cin >> s >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		dragons[i] = make_pair(x, y);
	}
	sort(dragons, dragons + n);

	bool win = true;
	for (int i = 0; i < n; i++)
	{
		if (s > dragons[i].first) s += dragons[i].second;
		else
		{
			win = false;
			break;
		}
	}

	cout << (win ? "YES" : "NO") << '\n';
	return 0;
}
