/**
 * Opis: (Binary Indexed Tree) $O(\log N)$, indeksowane od $0$.
 *		 Update w punkcie, zapytanie na przedziale
*/

struct BIT { 
	vector<int> tree;
	int N;
	BIT() {N = 0;}
	BIT(int n) {
		N = n;
		tree.resize(N);
	}
	void resize(int n) {
		N = n;
		tree.resize(N);
	}
	void update(int p, int x) {
		for (++p; p <= N; p += (p&-p)) tree[p-1] += x;
	}
	int sum(int r) {
		int res = 0;
		for (; r > 0; r -= (r&-r)) res += tree[r-1];
		return res;
	}
	int query(int l, int r) {return sum(r+1)-sum(l);}
	int lower_bound(int sum) {
		int pos = 0;
		for (int pw = 1<<25; pw; pw>>=1) {
			int npos = pos+pw;
			if (npos <= N && tree[npos-1] < sum) {
				pos = npos; sum -= tree[pos-1];
			}
		}
		return pos;
	}
};
