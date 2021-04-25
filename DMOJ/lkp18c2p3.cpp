#include <bits/stdc++.h>

bool idk(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (long long) (x1 - x3) * (y2 - y3) - (long long) (x2 - x3) * (y1 - y3) < 0;
}

inline int contains(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) {
    bool d1 = idk(x1, y1, x2, y2, x, y), d2 = idk(x2, y2, x3, y3, x, y), d3 = idk(x3, y3, x1, y1, x, y);
    return d1 == d2 && d2 == d3;
}

using namespace std;

pair<int, int> points[100];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, x1, y1, x2, y2, x3, y3;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) cin >> points[i].first >> points[i].second;
    while (M--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int cnt = 0;
        for (int i = 0; i < N; i++) { cnt += contains(x1, y1, x2, y2, x3, y3, points[i].first, points[i].second); }
        cout << cnt << '\n';
    }
    return 0;
}
