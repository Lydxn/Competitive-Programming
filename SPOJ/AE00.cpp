#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int count = 0;
	for (int i = 1; i * i <= N; i++)
	{
		count += N / i - i + 1;
	}
	
	cout << count << "\n";
	return 0;
}
