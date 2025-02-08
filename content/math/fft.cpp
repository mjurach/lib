/**
 *	 Opis: Mnożenie wielomianów w $O(n \log n)$. 
 */

using ld = long double;
using cd = complex<long double>;
const double PI = acos(-1);

void fft(vector<cd> &a, int n, bool invert = false) {
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
		ld ang = 2 * PI / len * (invert ? -1 : 1);
		cd r_len(cos(ang), sin(ang));
		for (int i = 0; i < n; i += len) {
			cd r(1);
			for (int j = 0; j < len/2; ++j, r *= r_len) {
				cd u = a[i + j], v = r * a[i + j + len/2];
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
			}
		}
	}

	if (invert)
		for (cd &x : a) x /= n;
}

vector<int> conv(vector<int> a, vector<int> b) {
	if (a.empty() || b.empty()) return {};

	vector<cd> fa(all(a)), fb(all(b));
	int n = ssize(a) + ssize(b) - 1;
	int sz = 1;
	while (sz < ssize(a) + ssize(b) - 1) sz *= 2;
	fft(fa, sz);
	fft(fb, sz);
	for (int i = 0; i < sz; ++i) fa[i] *= fb[i];
	fft(fa, sz, true);

	vector<int> result(n);
	for (int i = 0; i < n; ++i) 
		result[i] = round(fa[i].real());
	return result;
}
