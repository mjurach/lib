const int mod = 998244353;

int add(int a, int b) {
	a += b;
	return a >= mod ? a-mod : a;
}

int sub(int a, int b) {
	return add(a, mod - b);
}

int mul(int a, int b) {
	return int(ll(a) * ll(b) % mod);
}

int powi(int a, int b) {
	for(int ret = 1;; b /= 2) {
		if(b == 0)
			return ret;
		if(b & 1)
			ret = mul(ret, a);
		a = mul(a, a);
	}
}
int inv(int x) {
	return powi(x, mod - 2);
} 

using vi = vector<int>;

vi mod_xn(const vi &a, int n) {
	return vi(a.begin(), a.begin() + min(ssize(a), n));
}

void sub(vi& a, const vi& b) {
	a.resize(max(ssize(a), ssize(b)));
	for (int i = 0; i < ssize(b); ++i) a[i] = sub(a[i], b[i]);
}

vector<vi> mod_xy(const vector<vi> &a, int n, int m) {
	vector<vi> b(a.begin(), a.begin() + min(ssize(a), n));
	for (int i = 0; i < min(ssize(a), n); ++i)
		b[i] = vi(b[i].begin(), b[i].begin() + min(ssize(b[i]), m));
	return b;
}

constexpr int root = 3;
void ntt(vi & a, int n, bool inverse = false) {
	a.resize(n);
	vi b(n);
	for(int w = n / 2; w; w /= 2, swap(a, b)) {
		int r = powi(root, (mod - 1) / n * w), m = 1;
		for(int i = 0; i < n; i += w * 2, m = mul(m, r)) for(int j = 0; j < w; ++j) {
			int u = a[i + j], v = mul(a[i + j + w], m);
			b[i / 2 + j] = add(u, v);
			b[i / 2 + j + n / 2] = sub(u, v);
		}
	}
	if(inverse) {
		reverse(a.begin() + 1, a.end());
		int invn = inv(n);
		for(int& e : a) e = mul(e, invn);
	}
} 

vector<int> conv(vector<int> a, vector<int> b) {
	if(a.empty() or b.empty()) return {};
	int n = max(ssize(a), ssize(b));
	int l = ssize(a) + ssize(b) - 1, sz = 1 << __lg(2 * l - 1);
	ntt(a, sz), ntt(b, sz);
	for (int i = 0; i < sz; ++i) a[i] = mul(a[i], b[i]);
	ntt(a, sz, true), a.resize(n);
	return a;
}

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
//	int n = max(ssize(a), ssize(b));
//	int m = max(ssize(a[0]), ssize(b[0]));
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

vi inv(const vi& a, int n) {
	vi v{inv(a[0])};
	for(int x = 1; x < n; x *= 2) {
		vi f = mod_xn(a, 2 * x), g = v;
		ntt(g, 2 * x);
		for (int k = 0; k < 2; ++k) {
			ntt(f, 2 * x);
			for (int i = 0; i < 2*x; ++i) f[i] = mul(f[i], g[i]);
			ntt(f, 2 * x, true);
			for (int i = 0; i < x; ++i) f[i] = 0;
		}
		sub(v, f);
	}
	return mod_xn(v, n);
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
