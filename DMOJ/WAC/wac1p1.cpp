#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	long long M;
	while (T--)
	{
		cin >> M;
		cout << (long long) ceil(sqrt(2.0L * M) + 0.5) << '\n';
	}
	return 0;
}
