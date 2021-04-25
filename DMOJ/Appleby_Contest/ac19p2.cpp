#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

    int N, L; string S;
    cin >> N >> L; cin.ignore(); getline(cin, S);
    for (int i = 0; i < N; i++) cout << char(S[i] == ' ' ? ' ' : (S[i] + L - 'a') % 26 + 'a');
    cout << '\n';
	return 0;
}
