#include <iostream>

using namespace std;

int iter;

bool happy(int N)
{
	int temp = N, sum = 0, rem = 0;
	while (temp) {
		rem = temp % 10;
		sum += rem * rem;
		temp /= 10;
	}

	++iter;
	return sum > 4 ? happy(sum) : sum == 1;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	cout << (happy(N) ? iter : -1) << "\n";
	return 0;
}
