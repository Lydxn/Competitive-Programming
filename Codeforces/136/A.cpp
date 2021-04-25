#include <iostream>

using namespace std;

int friends[100];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, p;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> p;
		friends[p] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		cout << friends[i] << ' ';
	}
	return 0;
}
