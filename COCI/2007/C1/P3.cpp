#include <bits/stdc++.h>

using namespace std;

int P[100];
vector<int> c;

int min_dist(int N, int X) {
    int res = INT_MAX;
    for (int i = 0; i < N; i++) res = min(res, abs(X - P[i]));
    return res;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, A, B, ans, dist, mini = 0;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> P[i];
    cin >> A >> B;
    
    sort(P, P + N);
    for (int i = 0; i < N - 1; i++) {
        int mid = (P[i] + P[i + 1]) >> 1;
        c.push_back(mid); c.push_back(mid - 1); c.push_back(mid + 1);
    }
    c.push_back(A); c.push_back(A + 1); c.push_back(B); c.push_back(B - 1);
    
    for (int X : c) {
        int dist = min_dist(N, X);
        if (X % 2 && X >= A && X <= B && dist > mini) mini = dist, ans = X;
    }
    
    cout << ans << '\n';
    return 0;
}
