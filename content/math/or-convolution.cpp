/**
 * 		Opis: $O(n \log n)$. Oblicza tablicę $c_k = \sum_{i \mid j = k} a_i \cdot b_j$.
 */

void sos(vector<int> &s, bool inverse = false) {
	int n = ssize(s);
	int l = 1;
	while (2*l <= n) l *= 2;
	for(int i=0;i<l;i++)
		for(int mask=0;mask<n;mask++)
			if((mask & (1<<i)) != 0)
				s[mask] += (inverse ? -s[mask^(1<<i)] : s[mask^(1<<i)]);
}

vector<int> or_convolution(vector<int> a, vector<int> b) {
	int sz = max(ssize(a), ssize(b));
	a.resize(sz); b.resize(sz);
	vector<int> c(sz);

	sos(a); sos(b);
	for (int i = 0; i < sz; ++i) c[i] = a[i] * b[i];
	sos(c, true);

	return c;
}
