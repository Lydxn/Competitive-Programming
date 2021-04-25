#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	int maxval = 0;
	maxval = max(maxval, a + b + c);
	maxval = max(maxval, a + b * c);
	maxval = max(maxval, (a + b) * c);
	maxval = max(maxval, a * b + c);
	maxval = max(maxval, a * (b + c));
	maxval = max(maxval, a * b * c);

	cout << maxval << '\n';
	return 0;
}
