#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    unsigned long long a, b, c;
    cin >> a >> b >> c;
    
    cout << (a + b + c) % 42069900169420ULL << "\n";
    return 0;
}
