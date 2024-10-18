/**
 * 	Opis: Preprocessing $O(n)$, query w $O(\log n \cdot T(n))$, gdzie $T(n)$ to czas operacji na przedziale bazowym.
 *		  Pamięć $O(n \log n)$.	
 */

const int base = 1<<20;
struct mergeSortTree
{
	vector<vector<int> > tree;
	void build(int w, vector<int>& A)
	{
		if(w >= base)
		{
			if(w - base < A.size())	tree[w].push_back({A[w-base]});
			return;
		}
		build(w*2, A);
		build(w*2+1, A);
		merge(tree[w*2].begin(), tree[w*2].end(),
		tree[w*2+1].begin(), tree[w*2+1].end(), 
		back_inserter(tree[w]));
		return;
	}
	mergeSortTree(vector<int>& A)
	{
		tree.resize(base*2);
		build(1, A);
	}
	int query(int w, int p, int k, int x, int y, int val)
	{
		if(p > y || k < x) return 0;//poza zapytaniem
		if(x <= p && k <= y)
		{
			auto it = upper_bound(tree[w].begin(), tree[w].end(), val);
			//tutaj robimy cos na przedziale bazowym zapytania
			return distance(tree[w].begin(), it);//returnujemy wynik tego przedzialu
		}
		return query(w*2, p, (p+k)/2, x, y, val) +
		query(w*2+1, (p+k)/2+1, k, x, y, val); //tu dowolna operacja (max, +, -, *, czy cokolwiek)
	}
	int query(int x, int y, int val) {return query(1, 0, base-1, x, y, val);}//ile mniejszych od val na (x, y)
};
