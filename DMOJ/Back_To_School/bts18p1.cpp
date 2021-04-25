#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S, T; int K, cnt = 0; bool flag = false;
	getline(cin, S); getline(cin, T), cin >> K;
	for (int i = 0; i < int(S.size()); i++) cnt += S[i] != T[i], flag |= isspace(S[i]) ^ isspace(T[i]);
	cout << (cnt <= K && !flag ? "Plagiarized" : "No plagiarism") << '\n';
	return 0;
}
