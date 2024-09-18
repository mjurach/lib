/**
 *	Opis: $O(n)$ preprocessing, update i query w $O(\log n)$. Update to zmiana wartosci w wierzcholku, query to max na sciezce.
 *		  Drzewo przedziałowe do dopisania tak jak w komentarzu.
 */

const int inf = 1e9+10;

//struct segtree {
//	segtree(int n = 0) {}
//	void update(int v, int x) {}
//	int query(int l, int r) {}
//};

struct HLD {
	int n;
	vector<vector<int>> g;
	segtree t;
	int timer;

	vector<int> sz, d, parent, path, c, pre;

	HLD(const vector<vector<int>> &graph): n(ssize(graph)), g(graph) {
		sz = d = parent = path = c = pre = vector<int> (n);
		
		d[0] = 0;
		dfs(0);

		path[0] = 0;
		timer = 0;
		make_hld(0);
		t = segtree(timer);
	}

	void dfs(int v, int p = -1) {
		parent[v] = p;
		sz[v] = 1;
		c[v] = -1;
		for (auto u : g[v]) {
			if (u == p) continue;
			d[u] = d[v] + 1;
			dfs(u, v);
			sz[v] += sz[u];
			if (c[v] == -1 || sz[c[v]] < sz[u]) c[v] = u;
		}
	}

	void make_hld(int v, int p = -1) {
		pre[v] = timer++;
		if (c[v] != -1) {
			path[c[v]] = path[v];
			make_hld(c[v], v);
		}
		for (auto u : g[v]) {
			if (u == p || u == c[v]) continue;
			path[u] = u;
			make_hld(u, v);
		}
		//post[v] = timer++;
	}

	void update(int v, int x) {
		t.update(pre[v], x);	
	}
