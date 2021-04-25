#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string mode;
    double ra, ga, ba, rb, gb, bb;
    cin >> mode >> ra >> ga >> ba >> rb >> gb >> bb;
    
    cout << fixed << setprecision(7);
    if (mode == "Multiply") cout << ra * rb << ' ' << ga * gb << ' ' << ba * bb << '\n';
    else if (mode == "Screen") cout << 1 - (1 - ra) * (1 - rb) << ' ' << 1 - (1 - ga) * (1 - gb) << ' ' << 1 - (1 - ba) * (1 - bb) << '\n';
    else cout << (ra < 0.5 ? 2 * ra * rb : 1 - 2 * (1 - ra) * (1 - rb)) << ' ' << (ga < 0.5 ? 2 * ga * gb : 1 - 2 * (1 - ga) * (1 - gb)) << ' ' << (ba < 0.5 ? 2 * ba * bb : 1 - 2 * (1 - ba) * (1 - bb)) << '\n';
    return 0;
}
