#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;

	long long div3, div5, div15;
	while (T--)
	{
		cin >> N;
		N--;

		div3 = N / 3, div5 = N / 5, div15 = N / 15;
		cout << 3 * div3 * (div3 + 1) / 2 +
				5 * div5 * (div5 + 1) / 2 -
				15 * div15 * (div15 + 1) / 2 << '\n';
	}
	return 0;
}
