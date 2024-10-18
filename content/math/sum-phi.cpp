/**
 *	Opis: $O(n^{2/3})$ dla $HI = n^{2/3}$. Liczy $\sum_{i=1}^n \varphi(n)$.
 */

struct sieve {
	vector<int> phi;
	sieve(int n) {
		phi.resize(n+1);
		for (int i = 0; i <= n; ++i) phi[i] = i;

		for (int i = 2; i <= n; ++i) {
			if (phi[i] == i) {
				for (int j = i; j <= n; j += i)
					phi[j] -= phi[j]/i;
			}
		}
	}
};

const int HI = 1'000'003;
sieve S(HI);

unordered_map<int, int> mem;
vector<int> small(HI);

int sum_phi(int n) {
	if (n < HI) return small[n];
	if (mem[n] > 0) return mem[n];

	int res = ll(n) * (n+1) / 2 % mod;
	for (int l = 2, r; l <= n; l = r) {
		int k = n / l;	
		r = n / k + 1;
		res = sub(res, mul((r - l), sum_phi(k)));
	}
	return mem[n] = res;
}
