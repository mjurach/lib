/**
 * 	Opis: $O(\log^* n)$ czasowo. Jeżeli $e[x] < 0$ to $x$ jest korzeniem,
 *		  a $-e[x]$ to rozmiar spójnej. Jeżeli $e[x] \geq 0$ to jest to ojciec $x$.
 */


struct UF {
	vector<int> e;
	UF(int n):e(n, -1) {}

	int get(int a) {return e[a] < 0 ? a : e[a] = get(e[a]);}

	void unionn(int a, int b) {
		a = get(a); b = get(b);
		if(a == b) return;
		if(-e[a] > -e[b]) swap(a, b);
		e[b] += e[a];
		e[a] = b;
	}
};
