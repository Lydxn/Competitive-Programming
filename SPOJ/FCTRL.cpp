#include <iostream>

using namespace std;

int Z(int N)
{
	int count = 0;
	for (int i = 5; N / i; i *= 5)
	{
		count += N / i;
	}
	return count;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << Z(N) << "\n";
	}
	return 0;
}
