/**
 *   Opis: $O(n_1^2 n_2)$. Zwraca z czym jest zmatchowany wierzchołek (lub $-1$).
 */

bool try_kuhn(int v, vector<int> &mt, vector<bool> &used, const vector<vector<int>> &g) {
	if (used[v]) return false;
	used[v] = true;
	for (int u : g[v]) {
		if (mt[u] == -1 || try_kuhn(mt[u], mt, used, g)) {
			mt[u] = v;
			return true;
		}
	}

	return false;
}

vector<int> matching(const vector<vector<int>> &g, const vector<bool> &col) {
	int n = ssize(g);
	vector<int> mt(n, -1);
	vector<bool> used(n, false);

	for (int v = 0; v < n; ++v) {
		if (col[v]) continue;
        for (int to : g[v]) {
            if (mt[to] == -1) {
                mt[to] = v;
                used[v] = true;
                break;
            }
        }
    }

	for (int v = 0; v < n; ++v) {
		if (col[v] || used[v]) continue;
		used.assign(n, false);
		try_kuhn(v, mt, used, g);
	}

	for (int i = 0; i < n; ++i) {
		if (mt[i] != -1) mt[mt[i]] = i;
	}

	return mt;
}

