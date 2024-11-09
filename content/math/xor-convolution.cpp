/**
 * 		Opis: $O(n \log n)$. Oblicza tablicę $c_k = \sum_{i \wedge j = k} a_i \cdot b_j$.
 */

#include "mod.cpp" //keep-include

void transform(vector<int> &a, bool inverse = false) {
	int m = ssize(a);
	for (int n = (inverse ? 1 : m / 2); inverse ? n < m : n > 0; inverse ? n *= 2 : n /= 2)
		for (int i = 0; i < m; i += 2 * n)
			for (int j = 0; j < n; j++) {
				int x = a[i + j], y = a[i + j + n];
				a[i + j] = add(x, y);
				a[i + j + n] = sub(x, y); 
			}
}

vector<int> xor_convolution(vector<int> a, vector<int> b) {
	int sz = max(ssize(a), ssize(b));
	a.resize(sz); b.resize(sz);
	vector<int> c(sz);

	transform(a); transform(b);
	for (int i = 0; i < sz; ++i) c[i] = mul(a[i], b[i]); 
	transform(c, true);

	int mrev = inverse(m);
	for (int &x : c)
		x = mul(x, mrev);

	return c;
}
