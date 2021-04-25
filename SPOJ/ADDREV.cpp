#include <iostream>

using namespace std;

int rev(int N)
{
	int res = 0;
	while (N)
	{
		res = res * 10 + N % 10;
		N /= 10;
	}
	return res;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, A, B;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		cout << rev(rev(A) + rev(B)) << "\n";
	}
	return 0;
}
