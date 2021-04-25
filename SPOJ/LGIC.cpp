#include <iostream>

using namespace std;

long long a(int N)
{
	long long res = 1;
	for (int i = 2; i <= N; i++)
	{
		res *= i;
	}
	return res + (1 << N) - N;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	cout << a(N) << "\n";
	return 0;
}
