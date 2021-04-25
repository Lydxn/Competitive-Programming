#include <bits/stdc++.h>

using namespace std;

void radix_sort(int* a, int N)
{
    const int INT_BIT_SIZE = sizeof(int) << 3, RADIX = 0x100, MASK = RADIX - 1, MASK_BIT_LENGTH = 8;
    int *result = new int[N](), *buckets = new int[RADIX](), *startIndex = new int[RADIX](), *temp = nullptr;
    int flag = 0, key = 0;

    bool has_neg = false;
    while (flag < INT_BIT_SIZE)
    {
        for (int i = 0; i < N; ++i)
        {
            key = (a[i] & (MASK << flag)) >> flag;
            if (key < 0)
            {
                key += MASK;
                has_neg = true;
            }
            ++buckets[key];
        }

        startIndex[0] = 0;
        for (int j = 1; j < RADIX; ++j) startIndex[j] = startIndex[j - 1] + buckets[j - 1];

        for (int i = N - 1; i >= 0; --i)
        {
            key = (a[i] & (MASK << flag)) >> flag;
            if (key < 0) key += MASK;
            result[startIndex[key] + --buckets[key]] = a[i];
        }

        memcpy(a,result, N * sizeof(int));
        flag += MASK_BIT_LENGTH;
    }

    if (has_neg)
    {
        int indexOfNeg = 0;
        for (int i = 0; i < N; ++i)
        {
            if (a[i] < 0)
            {
                indexOfNeg = i;
                break;
            }
        }

        memcpy(a,result+indexOfNeg,(N-indexOfNeg)*sizeof(int));
        memcpy(a+(N-indexOfNeg),result,indexOfNeg*sizeof(int));
    }

    delete[] result;
    delete[] buckets;
    delete[] startIndex;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, m = INT_MAX;
    cin >> N;

    int* A = new int[N];
    for (int i = 0; i < N; ++i) cin >> A[i];

    radix_sort(A, N);
    for (int i = 1; i < N; ++i) m = min(m, A[i] - A[i - 1]);

    cout << m << '\n';
    return 0;
}
