/**
 * Opis: $O(\log n)$. Zwraca takie $x$, że $x \equiv a \mod m$ i $x \equiv b \mod n$.
 *		 Mogą nie być względnie pierwsze ale wtedy assert wywali.
 */


ll crt(ll a, ll m, ll b, ll n) {
	if(n > m) swap(a, b), swap(m, n);
	auto [d, x, y] = euclid(m, n);
	assert((a - b) % d == 0);
	ll ret = (b - a) % n * x % n / d * m + a;
	return ret < 0 ? ret + m * n / d : ret;
}
