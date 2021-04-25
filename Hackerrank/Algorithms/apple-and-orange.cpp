#include <iostream>

using namespace std;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  int s, t, a, b, m, n, dist, a_count = 0, o_count = 0;
  cin >> s >> t >> a >> b >> m >> n;

  while (m--) {
    cin >> dist;
    if (s <= a + dist && a + dist <= t)
      a_count++;
  }

  while (n--) {
    cin >> dist;
    if (s <= b + dist && b + dist <= t)
      o_count++;
  }

  cout << a_count << '\n' << o_count << '\n';
  return 0;
}
