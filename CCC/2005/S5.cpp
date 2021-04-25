#include <bits/stdc++.h>

using namespace std;

pair<int, int> scores[100000];
int BIT[100001], t;

void update(int x, int v)
{
    for (; x <= t; x += x & -x) BIT[x] += v;
}

int query(int x)
{
    int sum = 0;
    for (; x > 0; x -= x & -x) sum += BIT[x];
    return sum;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int score;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        cin >> score;
        scores[i] = make_pair(score, i + 1);
    }
    
    sort(scores, scores + t);
    
    double ans = 0;
    for (int i = 0; i < t; i++)
    {
        update(scores[i].second, 1);
        ans += scores[i].second - query(scores[i].second - 1);
    }
    
    cout << fixed << setprecision(2);
    cout << ans / t << '\n';
    return 0;
}
