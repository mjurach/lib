#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
auto&operator<<(auto &o, pair<auto, auto> p) {o << "(" << p.first << ", " << p.second << ")"; return o;}
auto&operator<<(auto &o, auto x) {o<<"{"; for(auto e : x) o<<e<<", "; return o<<"}";}
#define debug(X) cerr << "["#X"]: " << X << '\n';
#else 
#define cerr if(0)cout
#define debug(X) ;
#endif
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define ssize(x) int(x.size())
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back

using D = long double;
const D eps = 1e-9;

bool equal(D a, D b) {
	return abs(a - b) < eps;
}

struct point {
	D x, y;
	point (D a = 0, D b = 0): x(a), y(b) {}
	friend point operator - (const point &a, const point &b) {
		return point(a.x - b.x, a.y - b.y);	
	}
	friend bool operator == (const point &a, const point &b) {
		return mp(a.x, a.y) == mp(b.x, b.y);
	}

	friend istream& operator >> (istream &is, point &a) {
		return is >> a.x >> a.y;
	}
};

int sign(D x) {return equal(x, 0) ? 0 : (x > 0 ? 1 : -1);}

D cross(point a, point b) {
	return a.x * b.y - a.y * b.x;
}

D cross(point a, point b, point c) {
	return cross(a-c, b);
}

D dot(point a, point b) {
	return a.x * b.x + a.y * b.y;
}

D abs(point a) {
	return sqrt(a.x*a.x + a.y*a.y);
}

D dist(point a, point b) {
	return abs(a-b);
}

int dir(point a, point b, point c) {return sign(cross(a, b, c));}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	
	return 0;
}
