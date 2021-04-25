#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct node
{
	long long x, y, cost[3];
};

char grid[1001][1001];
long long dist[1001][1001];
bool visited[1000][1000];
pair<long long, long long> dir[3] = { { 0, 1 }, { -1, 0 }, { 1, 0 } };
queue<node> q;

void BFS(long long N)
{
    visited[0][0] = true;
	q.push({ 0, 0, 0, 0, 0 });
	for (long long i = 0; i < N; i++)
		for (long long j = 0; j < N; j++)
			dist[i][j] = LONG_MAX;

	while (!q.empty())
	{
		node curr = q.front();
		long long x = curr.x, y = curr.y;
		q.pop();

		for (long long i = 0; i < 3; i++)
		{
			curr.cost[i]++;
			long long nx = x + dir[i].first, ny = y + dir[i].second, val = pow(curr.cost[0], 2) + pow(curr.cost[1], 2) + pow(curr.cost[2], 2);
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && grid[ny][nx] != '#' && !visited[ny][nx] && dist[ny][nx] > val)
			{
				dist[ny][nx] = val;
				q.push({ nx, ny, curr.cost[0], curr.cost[1], curr.cost[2] });
			}
			curr.cost[i]--;
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	if (N == 1)
	{
	    cout << 0 << '\n';
	    return 0;
	}

	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < N; j++) grid[i][j] = s[j];
	}

	BFS(N);
	cout << (dist[N - 1][N - 1] == LONG_MAX ? -1 : dist[N - 1][N - 1]) << '\n';
	return 0;
}
