#include <iostream>

using namespace std;

int D[1000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) cin >> D[i];

	cout << "Thanos is on Planet: ";
	for (int i = 1; i < N; i++)
	{
		putchar(D[i] * D[i - 1] % 26 + 'A');
	}
	return 0;
}
