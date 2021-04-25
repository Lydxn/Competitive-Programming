#include <iostream>

using namespace std;

int scores[50];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> scores[i];
	int kth = scores[k - 1];

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (scores[i] >= kth && scores[i] > 0) count++;
	}

	cout << count << '\n';
	return 0;
}
