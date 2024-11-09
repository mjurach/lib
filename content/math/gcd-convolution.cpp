/**
 * 		Opis: $O(n \log n)$. Oblicza tablicę $c_k = \sum_{\gcd(i, j) = k} a_i \cdot b_j$.
 */

#include "mod.cpp" //keep-include

vector<int> gcd_convolution(vector<int> a, vector<int> b) {
	int sz = max(ssize(a), ssize(b));
	a.resize(sz); b.resize(sz);
	for (int i = 1; i < sz; ++i) { 
		for (int j = 2*i; j < sz; j += i) {
			a[i] = add(a[i], a[j]);
			b[i] = add(b[i], b[j]);
		}
	}
	
	vector<int> c(sz);
	for (int i = 0; i < sz; ++i) c[i] = mul(a[i], b[i]);

	for (int i = sz-1; i >= 1; --i)
		for (int j = 2*i; j < sz; j += i)
			c[i] = sub(c[i], c[j]);

	return c;
}
