const int mod = 998244353;
const int g = 3;
const int g_1 = 332748118;

int add(int a, int b) {
	a += b;
	return a >= mod ? a-mod : a;
}

int sub(int a, int b) {
	return add(a, mod-b);
}

int mul(int a, int b) {
	return int(((ll)a*b)%mod);
}

int fpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b&1) {
			res = mul(a, res); 
			b--;
		}
		a = mul(a, a);
		b /= 2;
	}
	return res;
}

int inv(int x) {
	return fpow(x, mod-2);
}

vector<int> mod_xn(const vector<int> &v, int n) {
	return vector<int>(v.begin(), v.begin() + min(n, ssize(v))); 
}

vector<int> add(vector<int> a, const vector<int> &b) {
	a.resize(max(ssize(a), ssize(b)));
	for (int i = 0; i < ssize(b); ++i)
		a[i] = add(a[i], b[i]);
	return a;
}

vector<int> sub(vector<int> a, const vector<int> &b) {
	a.resize(max(ssize(a), ssize(b)));
	for (int i = 0; i < ssize(b); ++i)
		a[i] = sub(a[i], b[i]);
	return a;
}

vector<int> deriv(vector<int> p) {
	for (int i = 1; i < ssize(p); ++i) p[i] = mul(p[i], i);
	if (ssize(p)) p.erase(p.begin());
	return p;
}

vector<int> integr(vector<int> p) {
	for (int i = 0; i < ssize(p); ++i)
		p[i] = mul(p[i], inv(i+1));
	p.insert(p.begin(), 0);
	return p;
}

void ntt(vector<int> &a, int n, bool invert = false) {
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

vector<int> conv(vector<int> a, vector<int> b) {
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


vector<int> inv(vector<int> p, int n) {
	if (n == 1)
		return {inv(p[0])};
	p.resize(n);
	vector<int> _p = p;
	for (int i = 1; i < n; i += 2) _p[i] = sub(0, p[i]);

	vector<int> t = mod_xn(conv(p, _p), n);
	for (int i = 1; i < n; i += 2) assert(t[i] == 0);
	for (int i = 0; i < n; i += 2)
		t[i/2] = t[i];
	t = inv(t, (n+1)/2);
	t.resize(n);
	for (int i = (n-1)/2; i >= 0; --i) {
		t[2*i] = t[i];
		if(i) t[i] = 0;
	}
	return mod_xn(conv(_p, t), n);
}

vector<int> log(const vector<int> &p, int n) {
	assert(ssize(p) && p[0] == 1);
	return integr(mod_xn(conv(deriv(mod_xn(p, n)), inv(p, n)), n-1));
}

vector<int> exp(const vector<int> &p, int n) {
	assert(p.empty() || p[0] == 0);
	vector<int> q = {1};
	for (int x = 1; x < n; x *= 2)
		q = mod_xn(conv(q, add(sub({1}, log(q, 2*x)), mod_xn(p, 2*x))), 2*x);
	q.resize(n);
	return q;
}
