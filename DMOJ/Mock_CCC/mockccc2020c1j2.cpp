#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int Uc, Um, K, ans = 0;
    cin >> Uc >> Um >> K;

    for (int i = 0; i <= K; i++) ans = max(ans, i * Uc + (K - i) * Um);
    cout << ans << '\n';
    return 0;
}
