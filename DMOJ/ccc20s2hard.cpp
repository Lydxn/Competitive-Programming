#include <bits/stdc++.h>

using namespace std;

bool vis[16000001];
int vv[16000001], vcur[16000001], vnxt[16000001], q[16000001], qidx, vidx;

bool can_escape(int M, int N, vector<vector<int>> v) {
	vidx = qidx = 0;
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			vv[++vidx] = v[i][j], vnxt[vidx] = vcur[i * j], vcur[i * j] = vidx;
	memset(vis, false, sizeof(vis)), vis[q[++qidx] = 1] = true;
	while (qidx) {
		int v = q[qidx--];
		if (v == M * N) return true;
		for (int i = vcur[v]; i; i = vnxt[i])
			if (!vis[vv[i]]) vis[q[++qidx] = vv[i]] = true;
	}
	return false;
}
