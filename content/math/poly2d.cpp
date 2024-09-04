/**
 * Opis: Operacje na wielmianach $\mod 998244353$.
 * 		 Mnożenie w $O(mn \log(m+n))$.
 * 		 Dzielenie zwraca vector współczynników przy $x^{n-1}$, w czasie $O(mn \log^2(n+m))$.
*/

#include "poly.cpp" //keep-include

void ntt(vector<vi> &a, int n, int m, bool inverse = false) {
	a.resize(n);
	for (int i = 0; i < ssize(a); ++i)
		ntt(a[i], m, inverse);
	for (int j = 0; j < ssize(a[0]); ++j) {
		vi c;
		for (int i = 0; i < ssize(a); ++i)
			c.eb(a[i][j]);
		ntt(c, n, inverse);
		for (int i = 0; i < ssize(a); ++i)
			a[i][j] = c[i];
	}
}

vector<vi> conv(vector<vi> a, vector<vi> b, int n, int m) {
	if (a.empty() || b.empty()) return {};
	int l1 = ssize(a) + ssize(b) - 1, sz1 = 1 << __lg(2*l1-1);
	int l2 = ssize(a[0]) + ssize(b[0]) - 1, sz2 = 1 << __lg(2*l2-1);

	ntt(a, sz1, sz2);
	ntt(b, sz1, sz2);
	for (int i = 0; i < sz1; ++i) 
		for (int j = 0; j < sz2; ++j) a[i][j] = mul(a[i][j], b[i][j]);
	ntt(a, sz1, sz2, true);
	a.resize(n);
	for (int i = 0; i < n; ++i) a[i].resize(m);
	return a;
}

vi div(vector<vi> b, vector<vi> a, int n, int m) {
	if (n == 1) {
		return conv(b[0], inv(a[0], m));
	}
	vector<vi> q = a;
	for (int i = 1; i < n; i += 2)
		for (int j = 0; j < ssize(a[i]); ++j) q[i][j] = sub(0, q[i][j]);

	vector<vi> v = conv(a, q, n, 2*m);
	debug(v);
	q = conv(b, q, n, 2*m);
	for (int i = 0; i < ssize(v); i += 2) {
		for (int j = 0; j < ssize(v[i]); ++j) {
			v[i/2][j] = v[i][j];
		}
	}
	v.resize((n+1)/2);

	if (n%2 == 0) {
		for (int i = 1; i < n; i += 2)
			for (int j = 0; j < 2*m; ++j)
				q[i/2][j] = q[i][j];
		q.resize(n/2);
		return div(q, v, n/2, 2*m);
	}
	else {
		for (int i = 0; i < n; i += 2)
			for (int j = 0; j < 2*m; ++j)
				q[i/2][j] = q[i][j];
		q.resize((n+1)/2);
		return div(q, v, (n+1)/2, 2*m);
	}
}
