/**
 *	Opis: $O(\log n)$ czasowo. Union find z roll backami --
 * 		  \texttt{roll$\textunderscore$back(x)} cofa ostatine $x$ operacji unionn 
 *		  (union wierzchołków z tego samego zbioru się nie liczy).
 */

struct dynamicUF {
	vector<int> e;
	dynamicUF(int n):e(n, -1) {}
	stack<array<int, 3>> s;

	int get(int a) {
		while(e[a] >= 0) a = e[a];
		return a;
	}


	int unionn(int a, int b) {
		a = get(a); b = get(b);
		if(a == b) return 0;
		if(-e[a] > -e[b]) swap(a, b);
		s.push({a, b, e[a]});
		e[b] += e[a];
		e[a] = b;
		return 1;
	}

	void roll_back(int m = 1) {
		while (m--) {
			auto [a, b, sz] = s.top();
			s.pop();
			e[b] -= sz;
			e[a] = sz;
		}
	}
};
