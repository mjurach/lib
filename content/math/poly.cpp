/**
 * Opis: Operacje na wielmianach $\mod 998244353$.
 *		 Można przepisać co się chce, przy funkcjach jest napisane co potrzeba. 
 * 		 deriv, integr w $O(n)$. inv, log, exp w $O(n \log n)$.
*/

#include "ntt.cpp" //keep-include

using vi = vector<int>;
vi mod_xn(const vi &v, int n) { //ZAWSZE
	return vi(v.begin(), v.begin() + min(n, ssize(v))); 
}

vi add(vi a, const vi &b) {
	a.resize(max(ssize(a), ssize(b)));
	for (int i = 0; i < ssize(b); ++i)
		a[i] = add(a[i], b[i]);
	return a;
}

vi sub(vi a, const vi &b) { //ZAWSZE
	a.resize(max(ssize(a), ssize(b)));
	for (int i = 0; i < ssize(b); ++i)
		a[i] = sub(a[i], b[i]);
	return a;
}

vi deriv(vi p) {
	for (int i = 1; i < ssize(p); ++i) p[i] = mul(p[i], i);
	if (ssize(p)) p.erase(p.begin());
	return p;
}

vi integr(vi p) {
	for (int i = 0; i < ssize(p); ++i)
		p[i] = mul(p[i], inv(i+1));
	p.insert(p.begin(), 0);
	return p;
}

vi inv(vi p, int n) {
	if (n == 1)
		return {inv(p[0])};
	p.resize(n);
	vi _p = p;
	for (int i = 1; i < n; i += 2) _p[i] = sub(0, p[i]);

	vi t = mod_xn(conv(p, _p), n);
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

vi log(const vi &p, int n) { //DERIV, INV, INTEGR
	assert(ssize(p) && p[0] == 1);
	return integr(mod_xn(conv(deriv(mod_xn(p, n)), inv(p, n)), n-1));
}

vi exp(const vi &p, int n) { //ADD, LOG
	assert(p.empty() || p[0] == 0);
	vi q = {1};
	for (int x = 1; x < n; x *= 2)
		q = mod_xn(conv(q, add(sub({1}, log(q, 2*x)), mod_xn(p, 2*x))), 2*x);
	q.resize(n);
	return q;
}
