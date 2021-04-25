#include <bits/stdc++.h>

using namespace std;

pair<int, int> gifts[7];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, ans = INT_MAX, curr, sum = 0;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> gifts[i].first >> gifts[i].second;
        sum += gifts[i].second;
    }
    sort(gifts, gifts + N);
    
    do {
        curr = 0;
        for (int i = 0, j = 101, k = sum; i < N; i++) {
            curr += k * (abs(j - gifts[i].first) + 1);
            j = gifts[i].first, k -= gifts[i].second;
        }
        ans = min(ans, curr);
    } while (next_permutation(gifts, gifts + N));
    
    cout << ans << '\n';
    return 0;
}
