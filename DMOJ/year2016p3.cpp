#include <algorithm>
#include <iostream>

using namespace std;

int snowballs[3000];
bool has[200002];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, next;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> snowballs[i];
		has[snowballs[i]] = true;
	}
	sort(snowballs, snowballs + N);

	int max_size = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
		    if (snowballs[i] != snowballs[j])
		    {
    			next = 2 * snowballs[j] - snowballs[i];
    			if (has[next]) max_size = max(max_size, snowballs[i] + snowballs[j] + next);
		    }
		}
	}

	cout << max_size << '\n';
	return 0;
}
