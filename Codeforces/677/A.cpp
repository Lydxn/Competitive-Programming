#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, h, a;
	cin >> n >> h;

	int min_width = 0;
	while (n--)
	{
		cin >> a;
		min_width += (a > h) + 1;
	}

	cout << min_width << '\n';
	return 0;
}
