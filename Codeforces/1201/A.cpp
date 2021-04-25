#include <algorithm>
#include <iostream>

using namespace std;

int freq[1000][70];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, score = 0, max_freq;
	cin >> n >> m;

	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++) ++freq[j][s[j]];
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a;

		max_freq = 0;
		for (int j = 'A'; j <= 'E'; j++) max_freq = max(max_freq, freq[i][j]);
		score += a * max_freq;
	}

	cout << score << '\n';
	return 0;
}
