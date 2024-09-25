/**
 * Opis: $O(n \log n)$. Mnożenie wielomianów $\mod 998244353$.
*/

#include "mod.cpp" //keep-include

const int g = 3;
const int g_1 = 332748118;

using vi = vector<int>;

void ntt(vi &a, int n, bool invert = false) {
	assert((n&(n-1)) == 0);
	a.resize(n);
	for (int i = 1, j = 0; i < n; ++i) {
		int bit = n/2;
		for ( ; bit&j; bit /= 2)
			j ^= bit;	
		j ^= bit;

		if (i < j) swap(a[i], a[j]);
	}

	for (int len = 2; len <= n; len *= 2) {
		int r_len = fpow(invert ? g_1 : g, (mod-1) / len);
		for (int i = 0; i < n; i += len) {
			int r = 1;
			for (int j = 0; j < len/2; ++j, r = mul(r, r_len)) {
				int u = a[i + j], v = mul(r, a[i + j + len/2]);
				a[i+j] = add(u, v);
				a[i+j+len/2] = sub(u, v);
			}
		}
	}

	if (invert) {
		int inv_n = inv(n);
		for (int &x : a) x = mul(x, inv_n);
	}
}

vi conv(vi a, vi b) {
	if (a.empty() || b.empty()) return {};
	int n = ssize(a) + ssize(b) - 1;
	int sz = 1;
	while (sz < ssize(a) + ssize(b) - 1) sz *= 2;
	ntt(a, sz);
	ntt(b, sz);
	for (int i = 0; i < sz; ++i) a[i] = mul(a[i], b[i]);
	ntt(a, sz, true);
	a.resize(n);
	return a;
}
