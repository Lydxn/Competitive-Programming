
using namespace std;

const int MAXN = 150001, BLKSZ = 400;
int L[MAXN], A[MAXN], pos[MAXN], shift[MAXN], len[MAXN], sum[MAXN / BLKSZ];
vector<int> lidx[MAXN], lval[MAXN], last[MAXN];

inline int get_val(int idx) {
    int x = L[idx];
    return lval[x][(pos[idx] - shift[x] + len[x]) % len[x]];
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, Q, op, l, r, x;
    cin >> N >> M >> Q;
    
    for (int i = 0; i < N; i++) {
        cin >> L[i];
        pos[i] = lidx[L[i]].size(), lidx[L[i]].push_back(i), ++len[L[i]];
    }
    
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < len[i]; j++) {
            if (lidx[i][j] / BLKSZ != lidx[i][(j + 1) % len[i]] / BLKSZ) last[i].push_back(lidx[i][j]);
        }
    }
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum[i / BLKSZ] += A[i], lval[L[i]].push_back(A[i]);
    }
    
    while (Q--) {
        cin >> op;
        if (op == 1) {
            cin >> l >> r;
            int bl = --l / BLKSZ, br = --r / BLKSZ, ans = 0;
            if (bl == br) for (int i = l; i <= r; i++) ans += get_val(i);
            else {
                for (int i = l; i < (bl + 1) * BLKSZ; i++) ans += get_val(i);
                for (int i = bl + 1; i < br; i++) ans += sum[i];
                for (int i = br * BLKSZ; i <= r; i++) ans += get_val(i);
            }
            cout << ans << '\n';
        } else {
            cin >> x;
            for (int i = 0; i < last[x].size(); i++) {
                int val = lval[x][(pos[last[x][i]] - shift[x] + len[x]) % len[x]];
                sum[last[x][i] / BLKSZ] -= val, sum[lidx[x][(pos[last[x][i]] + 1) % len[x]] / BLKSZ] += val;
            }
            shift[x] = (shift[x] + 1) % len[x];
        }
    }
    return 0;
}
