#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

bool comp(pii& a, pii&b) { return a.first == b.first ? a.second > b.second : a.first < b.first; }
pii box[100000];
int dp[100000];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, lis = 0;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> box[i].first >> box[i].second;

    sort(box, box + N, comp);
    for (int i = 0; i < N; i++) {
        int x = lower_bound(dp, dp + lis, box[i].second) - dp;
        dp[x] = box[i].second;
        if (x == lis) ++lis;
    }

    cout << lis << '\n';
    return 0;
}
