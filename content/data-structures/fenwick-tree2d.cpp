/**
 *		Opis: $O(\log^2 n)$. Dodaj w punkcie, suma na prostokącie.
 */

struct BIT2d { 
	vector<vector<int>> tree;
	int n, m;
	BIT2d() {n = m = 0;}
	BIT2d(int N, int M) {
		n = N; m = M;
		tree.resize(n, vector<int>(m));
	}
	void update(int x, int y, int v) {
		for (++x; x <= n; x += (x&-x))
			for (int p = y+1; p <= m; p += (p&-p))
				tree[x-1][p-1] += v;
	}
	int sum(int x, int y) {
		int res = 0;
		for (; x; x -= (x&-x)) 
			for (int j = y; j; j -= (j&-j)) 
				res += tree[x-1][j-1];
		return res;
	}
	int query(int x1, int y1, int x2, int y2) {return sum(x2+1, y2+1)-sum(x1, y2+1)-sum(x2+1, y1)+sum(x1, y1);}
};
