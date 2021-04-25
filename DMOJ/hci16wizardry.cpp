#include <iostream>

using namespace std;

const int MAXN = 2000001;
int spells[MAXN];

void dfs(int node)
{
	if (node != -1)
	{
		dfs(spells[node]);
		cout << node << " ";
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, e, i, a, b;
	cin >> n >> e >> i;

	fill_n(spells, MAXN, -1);
	while (e--)
	{
		cin >> a >> b;
		spells[b] = a;
	}
	
	dfs(spells[i]);
	return 0;
}
