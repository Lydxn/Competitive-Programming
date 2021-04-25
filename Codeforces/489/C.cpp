#include <algorithm>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int m, s;
	cin >> m >> s;

	if (!s) cout << (m == 1 ? "0 0" : "-1 -1") << '\n';
	else
	{
		string min_num, max_num;
		for (int i = 0; i < m; i++)
		{
			int dig = min(s, 9);
			max_num += dig + '0';
			s -= dig;
		}

		if (s)
		{
			cout << "-1 -1\n";
			return 0;
		}

		min_num = max_num;
		reverse(min_num.begin(), min_num.end());
		min_num[min_num.find_first_not_of('0')]--, min_num[0]++;

		cout << min_num << ' ' << max_num << '\n';
	}
	return 0;
}
