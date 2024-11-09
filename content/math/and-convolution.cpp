/**
 * 		Opis: $O(n \log n)$. Oblicza tablicę $c_k = \sum_{i \& j = k} a_i \cdot b_j$.
 */

#include "or_convolution.cpp" //keep-include

vector<int> and_convolution(vector<int> a, vector<int> b) {
	int n = max(ssize(a), ssize(b));
	int sz = 1;
	while (sz < n) sz *= 2;
	a.resize(sz); b.resize(sz);

	for (int i = 0; i < sz/2; ++i) {
		swap(a[i], a[(sz-1)^i]);
		swap(b[i], b[(sz-1)^i]);
	}

	vector<int> c = or_convolution(a, b);

	for (int i = 0; i < sz/2; ++i) {
		swap(c[i], c[(sz-1)^i]);
	}

	return c;
}
