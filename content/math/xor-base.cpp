/**
 * Opis: $O(nB)$ gdzie $B$ to liczba bitów. Zwraca minimalny zbiór $b$ taki że każdy element z $x$ można
 *		zapisać jako xor pewnych elementów $b$.
 */

vector<ll> xor_base(const vector<ll> &x) {
	vector<ll> basis;
	for (ll a: x) {
		ll A = a;
		for (ll b: basis) A = min(A,A^b);
		if (A) basis.push_back(A);
	}
	return basis;
}

