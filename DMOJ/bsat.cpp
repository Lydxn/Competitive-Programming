#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int arr[48];

vector<int> subset_sums(int l, int r)
{
	int len = r - l + 1;
	vector<int> res(1 << len);

	for (int i = 0; i < res.size(); i++)
	{
		int sum = 0;
		for (int j = 0; j < len; j++)
		{
			if (i & (1 << j))
			{
				sum += arr[j + l];
			}
		}
		res[i] = sum;
	}
	return res;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	vector<int> sums1 = subset_sums(0, N / 2);
	vector<int> sums2 = subset_sums(N / 2 + 1, N - 1);

	sort(sums1.begin(), sums1.end());
	sort(sums2.begin(), sums2.end());

	long long res = 0;
	int upper = sums2.size() - 1;

	for (int s : sums1)
	{
		while (upper >= 0 && s + sums2[upper] > K) --upper;
		res += upper + 1;
	}

	cout << res << "\n";
	return 0;
}
