#include <cmath>
#include <iostream>

using namespace std;

int max_triplet(int N)
{
	int a2b2, root, a, b, N2 = 2 * N, NN = N * N;
	for (int c = N / 3 + 1; c < N / 2; c++)
	{
		a2b2 = c * c - NN + N2 * c, root = sqrt(a2b2);
		if (root * root == a2b2)
		{
			b = (N - c + root) / 2, a = N - b - c;
			return a * b * c;
		}
	}
	return -1;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << max_triplet(N) << '\n';
	}
	return 0;
}
