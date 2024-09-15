/**
 * Opis: $O(\log n)$. Zwraca trójkę [d, x, y], że $d = \gcd(a, b)$ i $ax + by = d$.
*/

tuple<ll, ll, ll> euclid(ll a, ll b) {
	if (b == 0) return make_tuple(a, 1, 0);
	auto [d, x, y] = euclid(b, a%b);
	return make_tuple(d, y, x - (a/b) * y);
}
