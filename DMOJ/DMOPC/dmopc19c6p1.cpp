#include <bits/stdc++.h>

using namespace std;

using T = long double; using pt = complex<T>; const T EPS = 1e-9;
#define x real()
#define y imag()
#define ref const pt &

istream &operator >> (istream &stream, pt &p) { T X, Y; stream >> X >> Y; p.real(X); p.imag(Y); return stream; }
ostream &operator << (ostream &stream, ref p) { return stream << fixed << setprecision(9) << p.x << ' ' << p.y; }

bool lt(T a, T b) { return a + EPS < b; }
bool le(T a, T b) { return !lt(b, a); }
bool gt(T a, T b) { return lt(b, a); }
bool ge(T a, T b) { return !lt(a, b); }
bool eq(T a, T b) { return !lt(a, b) && !lt(b, a); }
bool ne(T a, T b) { return lt(a, b) || lt(b, a); }
int sgn(T a) { return lt(a, 0) ? -1 : gt(a, 0) ? +1 : 0; }

bool operator == (ref a, ref b) { return eq(a.x, b.x) && eq(a.y, b.y); }
bool operator != (ref a, ref b) { return !(a == b); }
struct pt_eq { bool operator () (ref a, ref b) const { return a == b; } };
struct pt_ne { bool operator () (ref a, ref b) const { return a != b; } };

// abs gets polar distance, arg gets polar angle
T dot(ref a, ref b) { return a.x * b.x + a.y * b.y; }
T cross(ref a, ref b) { return a.x * b.y - a.y * b.x; }
T norm(ref a) { return dot(a, a); }
T distSq(ref a, ref b) { return norm(b - a); }
T dist(ref a, ref b) { return abs(b - a); }
T ang(ref a, ref b) { return arg(b - a); }
// sign of ang, area2, ccw: -1 if clockwise, 0 if collinear, +1 if counterclockwise
T ang(ref a, ref b, ref c) { return remainder(ang(b, a) - ang(b, c), 2 * acos(T(-1))); }
T area2(ref a, ref b, ref c) { return cross(b - a, c - a); }
int ccw(ref a, ref b, ref c) { return sgn(area2(a, b, c)); }
// a rotated theta radians around p
pt rot(ref a, ref p, const T &theta) { return (a - p) * pt(polar(T(1), theta)) + p; }
pt perp(ref a) { return pt(-a.y, a.x); }

bool xOrdLt(ref a, ref b) { return lt(a.x, b.x); }
bool xOrdLe(ref a, ref b) { return !xOrdLt(b, a); }
bool xOrdGt(ref a, ref b) { return xOrdLt(b, a); }
bool xOrdGe(ref a, ref b) { return !xOrdLt(a, b); }
bool yOrdLt(ref a, ref b) { return lt(a.y, b.y); }
bool yOrdLe(ref a, ref b) { return !yOrdLt(b, a); }
bool yOrdGt(ref a, ref b) { return yOrdLt(b, a); }
bool yOrdGe(ref a, ref b) { return !yOrdLt(a, b); }
bool xyOrdLt(ref a, ref b) { return eq(a.x, b.x) ? lt(a.y, b.y) : lt(a.x, b.x); }
bool xyOrdLe(ref a, ref b) { return !xyOrdLt(b, a); }
bool xyOrdGt(ref a, ref b) { return xyOrdLt(b, a); }
bool xyOrdGe(ref a, ref b) { return !xyOrdLt(a, b); }
bool yxOrdLt(ref a, ref b) { return eq(a.y, b.y) ? lt(a.x, b.x) : lt(a.y, b.y); }
bool yxOrdLe(ref a, ref b) { return !yxOrdLt(b, a); }
bool yxOrdGt(ref a, ref b) { return yxOrdLt(b, a); }
bool yxOrdGe(ref a, ref b) { return !yxOrdLt(a, b); }
bool rOrdLt(ref a, ref b) { return lt(norm(a), norm(b)); }
bool rOrdLe(ref a, ref b) { return !rOrdLt(b, a); }
bool rOrdGt(ref a, ref b) { return rOrdLt(b, a); }
bool rOrdGe(ref a, ref b) { return !rOrdLt(a, b); }
function<bool(ref, ref)> ccwOrdLt(ref p) { return [=] (ref a, ref b) { return 0 < ccw(p, a, b); }; }
function<bool(ref, ref)> ccwOrdLe(ref p) { return [=] (ref a, ref b) { return 0 <= ccw(p, a, b); }; }
function<bool(ref, ref)> ccwOrdGt(ref p) { return [=] (ref a, ref b) { return 0 > ccw(p, a, b); }; }
function<bool(ref, ref)> ccwOrdGe(ref p) { return [=] (ref a, ref b) { return 0 >= ccw(p, a, b); }; }
function<bool(ref, ref)> distOrdLt(ref p) { return [=] (ref a, ref b) { return lt(distSq(p, a), distSq(p, b)); }; }
function<bool(ref, ref)> distOrdLe(ref p) { return [=] (ref a, ref b) { return le(distSq(p, a), distSq(p, b)); }; }
function<bool(ref, ref)> distOrdGt(ref p) { return [=] (ref a, ref b) { return gt(distSq(p, a), distSq(p, b)); }; }
function<bool(ref, ref)> distOrdGe(ref p) { return [=] (ref a, ref b) { return ge(distSq(p, a), distSq(p, b)); }; }

// returns iterator to first element equal to pivot
// cmp is the angle comparison function (ccwOrdLt or ccwOrdGt)
// rot is the rotation comparison function (xyOrdLt, xyOrdGt, yxOrdLt, yxOrdGt)
// points p that return true for rot(p, pivot) will appear before those that do not
// points that are equal to pivot appear after all other points
template <class It, class F1 = function<function<bool(ref, ref)>(ref)>, class F2 = function<bool(ref, ref)>>
        It sortByAng(ref pivot, It st, It en, F1 cmp = ccwOrdLt, F2 rot = yxOrdLt) {
    en = partition(st, en, [&] (ref p) { return p != pivot; });
    It mid = partition(st, en, [&] (ref p) { return rot(p, pivot); });
    function<bool(ref, ref)> pc = cmp(pivot); sort(st, mid, pc); sort(mid, en, pc); return en;
}

struct Line {
    pt v; T c;
    Line(T a = 0, T b = 0, T c = 0) : v(b, -a), c(c) {}
    Line(ref v, T c) : v(v), c(c) {}
    Line(ref p, ref q) : v(q - p), c(cross(v, p)) {}
    T eval(ref p) const { return cross(v, p) - c; }
    // -1 if left of line, 0 if on line, +1 if right of line
    int onLeft(ref p) const { return sgn(eval(p)); }
    T distSq(ref p) const { T e = eval(p); return e * e / norm(v); }
    T dist(ref p) const { return abs(eval(p) / abs(v)); }
    Line perpThrough(ref p) const { return Line(p, p + perp(v)); }
    // sort by othogonal projection
    function<bool(ref, ref)> cmpProjLt() const { return [=] (ref p, ref q) { return lt(dot(v, p), dot(v, q)); }; }
    function<bool(ref, ref)> cmpProjLe() const { return [=] (ref p, ref q) { return le(dot(v, p), dot(v, q)); }; }
    function<bool(ref, ref)> cmpProjGt() const { return [=] (ref p, ref q) { return gt(dot(v, p), dot(v, q)); }; }
    function<bool(ref, ref)> cmpProjGe() const { return [=] (ref p, ref q) { return ge(dot(v, p), dot(v, q)); }; }
    Line translate(ref p) const { return Line(v, c + cross(v, p)); }
    Line shiftLeft(T d) const { return Line(v, c + d * abs(v)); }
    pt proj(ref p) const { return p - perp(p) * eval(p) / norm(v); }
    pt refl(ref p) const { return p - perp(p) * T(2) * eval(p) / norm(v); }
};
int lineIntersection(const Line &l1, const Line &l2, pt &res) { // returns 0 if no intersection, 1 if proper intersection, 2 otherwise
    T d = cross(l1.v, l2.v);
    if (eq(d, 0)) return l2.v * l1.c == l1.v * l2.c ? 2 : 0;
    res = (l2.v * l1.c - l1.v * l2.c) / d; return 1;
}
Line bisector(const Line &l1, const Line &l2, bool interior) {
    T s = interior ? 1 : -1; return Line(l2.v / abs(l2.v) + l1.v / abs(l1.v) * s, l2.c / abs(l2.v) + l1.c / abs(l1.v) * s);
}

// returns true iff p is on the line segment a-b
bool onSeg(ref p, ref a, ref b) { return ccw(p, a, b) == 0 && le(dot(a - p, b - p), 0); }
int lineSegIntersects(ref a, ref b, ref p, ref q) { // returns 0 if no intersection, 1 if proper intersection, 2 otherwise
    int o1 = ccw(a, b, p), o2 = ccw(a, b, q), o3 = ccw(p, q, a), o4 = ccw(p, q, b);
    if (o1 != o2 && o3 != o4) return 1;
    else if ((o1 == 0 && onSeg(p, a, b)) || (o2 == 0 && onSeg(q, a, b)) || (o3 == 0 && onSeg(a, p, q)) || (o4 == 0 && onSeg(b, p, q))) return 2;
    else return 0;
}
vector<pt> lineSegIntersection(ref a, ref b, ref p, ref q) {
    int intersects = lineSegIntersects(a, b, p, q);
    if (intersects == 0) return vector<pt>();
    else if (intersects == 1) { T c1 = cross(p - a, b - a), c2 = cross(q - a, b - a); return vector<pt>{(c1 * q - c2 * p) / (c1 - c2)}; }
    vector<pt> ret;
    if (onSeg(p, a, b)) ret.push_back(p);
    if (onSeg(q, a, b)) ret.push_back(q);
    if (onSeg(a, p, q)) ret.push_back(a);
    if (onSeg(b, p, q)) ret.push_back(b);
    sort(ret.begin(), ret.end(), xyOrdLt); ret.erase(unique(ret.begin(), ret.end(), pt_eq()), ret.end()); return ret;
}
T segPtDist(ref p, ref a, ref b) {
    if (a != b) {
        Line l(a, b);
        if (l.cmpProjLt()(a, p) && l.cmpProjLt()(p, b)) return l.dist(p);
    }
    return min(dist(p, a), dist(p, b));
}
pt closestPtToSeg(ref p, ref a, ref b) {
    if (a != b) {
        Line l(a, b);
        if (l.cmpProjLt()(a, p) && l.cmpProjLt()(p, b)) return l.proj(p);
    }
    return lt(dist(p, a), dist(p, b)) ? a : b;
}
T segSegDist(ref a, ref b, ref p, ref q) {
    return lineSegIntersects(a, b, p, q) > 0 ? 0 : min({segPtDist(p, a, b), segPtDist(q, a, b), segPtDist(a, p, q), segPtDist(b, p, q)});
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    long double x1a, y1a, x2a, y2a, x1b, y1b, x2b, y2b;
    cin >> x1a >> y1a >> x2a >> y2a >> x1b >> y1b >> x2b >> y2b;

    Line a = Line({x1a, y1a}, {x2a, y2a}), b = Line({x1b, y1b}, {x2b, y2b});
    pt res; int ans = lineIntersection(a, b, res);
    if (ans == 1) cout << fixed << setprecision(6) << real(res) << ' ' << imag(res) << '\n';
    else cout << (ans == 0 ? "parallel" : "coincident") << '\n';
    return 0;
}
// this problem sucks
