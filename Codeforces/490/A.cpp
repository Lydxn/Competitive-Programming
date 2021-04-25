#include <algorithm>
#include <iostream>

using namespace std;

int skills[5001][4], cnt[4];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> t;
		skills[cnt[t]++][t] = i;
	}

	int w = min(cnt[1], min(cnt[2], cnt[3]));
	cout << w << '\n';

	for (int i = 0; i < w; i++)
	{
		cout << skills[i][1] << ' ' << skills[i][2] << ' ' << skills[i][3] << '\n';
	}
	return 0;
}
