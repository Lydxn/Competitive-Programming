#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct bin {
    ll s; int sz;
    bin() {}
    bin(ll s, int sz) : s(s), sz(sz) {}
    bool operator== (const bin& b) { return s == b.s; }
};

#define _substr(val, pos, len) bin((val.s >> (val.sz - (len) - (pos))) & ((1 << (len)) - 1), (len))
inline bin _bin(const string& s) {
    bin res = bin(0, s.size());
    for (int i = 0; i < res.sz; i++) {
        if (s[i] == 'B') res.s += 1LL << (res.sz - i - 1);
    }
    return res;
}
inline string _str(bin val) {
    string res = "";
    for (int i = 0; i < val.sz; i++) {
        res.push_back(val.s & 1 ? 'B' : 'A');
        val.s >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
}

struct sol {
    int R, P; bin W;
    sol(int R, int P, bin W) : R(R), P(P), W(W.s, W.sz) {}
};

bin rule[3][2], cur, F;
int rdiff[3][2], c[3], cnt;
vector<sol> path;
unordered_set<ll> vis;

void dfs(int S, bin cur) {
    if (cur.sz > 50) return;
    if (vis.count(cur.s << 12 | c[0] << 8 | c[1] << 4 | c[2])) return;
    vis.insert(cur.s << 12 | c[0] << 8 | c[1] << 4 | c[2]);

    if (S == 0) {
        if (cur == F) {
            for (const auto& p : path) cout << p.R + 1 << ' ' << p.P + 1 << ' ' << _str(p.W) << '\n';
            exit(0);
        }
        return;
    }
    ++cnt;
    for (int i = 0; i < 3; i++) {
        if (c[i]) {
            c[i]--;
            bin sub = rule[i][0];
            for (int j = cur.sz >> 1, k = 0; j >= 0; k++, j = k % 2 ? j + k : j - k) {
                if (_substr(cur, j, sub.sz) == sub) {
                    bin p1 = bin(cur.s >> (cur.sz - j), j), p2 = rule[i][1], p3 = bin(cur.s & ((1 << (cur.sz - j - sub.sz)) - 1), cur.sz - sub.sz - j);
                    bin res = bin(((p1.s << p2.sz) | p2.s) << p3.sz | p3.s, p1.sz + p2.sz + p3.sz);
                    path.emplace_back(i, j, res);
                    dfs(S - 1, res);
                    path.pop_back();
                }
            }
            c[i]++;
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int S, adiff, bdiff, a1, a2; bin I; string _I, _F, r1, r2;
    for (int i = 0; i < 3; i++) {
        cin >> r1 >> r2; rule[i][0] = _bin(r1), rule[i][1] = _bin(r2), a1 = __builtin_popcountll(rule[i][0].s), a2 = __builtin_popcountll(rule[i][1].s);
        rdiff[i][0] = a1 - a2;
        rdiff[i][1] = (rule[i][0].sz - a1) - (rule[i][1].sz - a2);
    }

    cin >> S >> _I >> _F; I = _bin(_I), F = _bin(_F);
    a1 = __builtin_popcountll(I.s), a2 = __builtin_popcountll(F.s), adiff = a1 - a2, bdiff = (I.sz - a1) - (F.sz - a2);

    for (c[0] = 0; c[0] <= S; c[0]++) {
        for (c[1] = 0; c[1] <= S - c[0]; c[1]++) {
            c[2] = S - c[0] - c[1];
            if (rdiff[0][0] * c[0] + rdiff[1][0] * c[1] + rdiff[2][0] * c[2] == adiff && rdiff[0][1] * c[0] + rdiff[1][1] * c[1] + rdiff[2][1] * c[2] == bdiff) {
                dfs(S, I);
            }
        }
    }
    return 0;
}
