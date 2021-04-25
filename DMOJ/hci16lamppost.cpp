#include <iostream>
#include <vector>

using namespace std;

int light[1000001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, C, C1, C2;
	cin >> N >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> C1 >> C2;
		light[C1]++;
		light[C2]++;
	}

	int max = 0;
	int maxI = 0;
	for (int i = 1; i <= N; i++)
	{
		if (max <= light[i])
		{
			max = light[i];
			maxI = i;
		}
	}

	cout << maxI << "\n";
	return 0;
}
