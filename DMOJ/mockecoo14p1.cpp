#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

char s[500][500];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	for (int _ = 0; _ < 5; _++) {
		cin >> N; int ptr = -1, mid = max(21, N * (N + 1) + 10) / 2;
		memset(s, ' ', sizeof(s));

		for (s[++ptr][mid] = '|'; ++ptr <= 3; ) s[ptr][mid + ptr - 4] = '\\', s[ptr][mid] = '|', s[ptr][mid - ptr + 4] = '/';
		for (int i = mid - 3; i <= mid + 3; i++) s[ptr][i] = 'X';
		++ptr, s[ptr][mid - 4] = s[ptr][mid + 4] = 'X';
		++ptr, s[ptr][mid - 5] = s[ptr][mid + 5] = 'X', s[ptr][mid - 2] = s[ptr][mid + 2] = 'O';
		++ptr, s[ptr][mid - 6] = s[ptr][mid + 6] = 'X', s[ptr][mid] = 'V';
		++ptr, s[ptr][mid - 6] = s[ptr][mid - 3] = s[ptr][mid + 3] = s[ptr][mid + 6] = 'X';
		++ptr, s[ptr][mid - 5] = s[ptr][mid + 5] = 'X'; for (int i = mid - 2; i <= mid + 2; i++) s[ptr][i] = 'X';
		++ptr, s[ptr][mid - 4] = s[ptr][mid + 4] = 'X';
		++ptr; for (int i = mid - 3; i <= mid + 3; i++) s[ptr][i] = 'X';

		for (int i = 0, ofs = 4; i < N; i++) {
			for (int j = 0; j < i + 3; j++, ofs++) {
				++ptr, s[ptr][mid - ofs] = s[ptr][mid + ofs] = 'X';
				if (j != 0 && j != i + 2) s[ptr][mid] = 'O';
			}
			++ptr, ofs -= 2; for (int j = mid - ofs; j <= mid + ofs; j++) s[ptr][j] = 'X';
		}

		++ptr; for (int i = mid - 4; i <= mid + 4; i++) if (i != mid) s[ptr][i] = 'O';
		++ptr; for (int i = mid - 4; i <= mid + 4; i++) if (i != mid) s[ptr][i] = 'O';
		s[8][mid - 10] = 'W', s[9][mid - 9] = s[10][mid - 8] = s[11][mid - 7] = s[12][mid - 6] = '\\';
		s[12][mid + 5] = s[12][mid + 6] = s[12][mid + 7] = '-', s[13][mid + 8] = s[14][mid + 9] = s[15][mid + 10] = '\\', s[16][mid + 11] = 'M';

		for (int i = 0; i <= ptr; i++) {
			string line = ""; bool flag = false;
			for (int j = 499; j >= 0; j--) if (flag || s[i][j] != ' ') line = s[i][j] + line, flag = true;
			cout << line << '\n';
		}
		if (i != 4) cout << '\n';
	}
	return 0;
}
