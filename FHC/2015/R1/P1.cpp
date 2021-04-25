#include <iostream>

using namespace std;

const int MAX = 10000001;
int primacities[MAX];

void init_p()
{
    for (int i = 2; i < MAX; i++)
    {
        if (!primacities[i])
        {
            for (int j = i; j < MAX; j += i) ++primacities[j];
        }
    }
}

int main()
{
    init_p();
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T, A, B, K, count;
    cin >> T;

    for (int i = 1; i <= T; ++i)
    {
        cin >> A >> B >> K;

        count = 0;
        for (int i = A; i <= B; ++i)
        {
            if (primacities[i] == K) ++count;
        }
        printf("Case #%d: %d\n", i, count);
    }
    return 0;
}
