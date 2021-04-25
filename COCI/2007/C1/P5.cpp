#include <bits/stdc++.h>

using namespace std;

int A[100000], freql[200001], freqr[200001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, B, idx, cnt = 0;
    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] == B) idx = i;
    }

    for (int i = idx, j = 0; i >= 0; i--) j += A[i] < B ? 1 : A[i] > B ? -1 : 0, ++freql[j + N];
    for (int i = idx, j = 0; i < N; i++)  j += A[i] > B ? 1 : A[i] < B ? -1 : 0, ++freqr[j + N];

    for (int i = 0; i <= N << 1; i++) cnt += freql[i] * freqr[i];
    cout << cnt << '\n';
    return 0;
}
