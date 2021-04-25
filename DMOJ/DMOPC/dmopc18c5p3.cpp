#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int C[200000];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N; ll M, l = 0, r = 0, sum = 0, ans = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> C[i];
    
    while (l < N) {
        while (r < N && sum + C[r] < M) sum += C[r++];
        sum -= C[l++], ans = max(ans, r - l + 1);
    }
    
    cout << ans << '\n';
    return 0; 
}
