#include <algorithm>
#include <iostream>

using namespace std;

int dig[1000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N, K, max_prod, prod;
	cin >> T;

	string num;
	while (T--)
	{
		cin >> N >> K >> num;
		for (int i = 0; i < N; i++) dig[i] =  num[i] - '0';
		
		max_prod = 0;
		for (int i = 0; i < N - K; i++)
		{
			prod = 1;
			for (int j = 0; j < K; j++) prod *= dig[i + j];
			max_prod = max(max_prod, prod);
		}
		cout << max_prod << '\n';
	}
	return 0;
}
