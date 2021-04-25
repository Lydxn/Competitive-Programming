#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, p, d;
	cin >> N >> K;

	vector<tuple<int, int, int>> price;

	for (int i = 0; i < N; i++)
	{
		cin >> p >> d;
		price.push_back(make_tuple(p - d, p, d));
	}
	sort(price.begin(), price.end());

	long long money = 0;
	for (int i = 0; i < N; i++)
	{
		money += i <= N - K ? get<1>(price[i]) : get<2>(price[i]);
	}
	
	cout << money << '\n';
	return 0;
}
