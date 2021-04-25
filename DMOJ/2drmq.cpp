#include <bits/stdc++.h>

using namespace std;

template <const int MAXN, const int MAXM, typename T>
struct SparseTable2D
{
	static const int MAXLGN = 32 - __builtin_clz(MAXN), MAXLGM = 32 - __builtin_clz(MAXM);
	int lg[max(MAXN, MAXM) + 1];
	T st[MAXLGN][MAXN][MAXLGM][MAXM];

	void init(const auto& a, const int N = MAXN, const int M = MAXM)
	{
		const int LGN = 32 - __builtin_clz(N), LGM = 32 - __builtin_clz(M);
		for (int ir = 0; ir < N; ir++)
		{
			for (int ic = 0; ic < M; ic++)
			{
				st[0][ir][0][ic] = a[ir][ic];
			}
		}

		for (int ir = 0; ir < N; ir++)
		{
			for (int jc = 0; jc < LGM - 1; jc++)
			{
				for (int ic = 0; ic + (1 << jc) < M; ic++)
				{
					st[0][ir][jc + 1][ic] = min(st[0][ir][jc][ic], st[0][ir][jc][ic + (1 << jc)]);
				}
			}
		}

		lg[1] = 0;
		for (int i = 2; i <= max(N, M); i++) lg[i] = lg[i >> 1] + 1;

		for (int jr = 0; jr < LGN - 1; jr++)
		{
			for (int ir = 0; ir + (1 << jr) < N; ir++)
			{
				for (int jc = 0; jc < LGM; jc++)
				{
					for (int ic = 0; ic < M; ic++)
					{
						st[jr + 1][ir][jc][ic] = min(st[jr][ir][jc][ic], st[jr][ir + (1 << jr)][jc][ic]);
					}
				}
			}
		}
	}

	T query(int u, int d, int l, int r)
	{
		int kr = lg[d - u + 1], kc = lg[r - l + 1];
		return min(min(st[kr][u][kc][l], st[kr][u][kc][r - (1 << kc) + 1]),
				   min(st[kr][d - (1 << kr) + 1][kc][l], st[kr][d - (1 << kr) + 1][kc][r - (1 << kc) + 1]));
	}
};

const int MAXN = 1000;
SparseTable2D<MAXN, MAXN, uint32_t> st;

void init(vector<vector<int>> arr)
{
	st.init(arr, arr.size(), arr.size());
}

int query(int a, int b, int c, int d)
{
    if (b - a == -1) return 1;
    return st.query(a, b, c, d);
}
