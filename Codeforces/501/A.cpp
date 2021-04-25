#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int misha = max(3 * a / 10, a - a / 250 * c), vasya = max(3 * b / 10, b - b / 250 * d);
    
    cout << (misha > vasya ? "Misha" : misha < vasya ? "Vasya" : "Tie") << '\n';
    return 0;
}
