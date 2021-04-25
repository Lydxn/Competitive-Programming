#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	while (cin >> N && N != 0)
	{
		cout << N * (N + 1) * (2 * N + 1) / 6 << "\n";
	}
	return 0;
}
