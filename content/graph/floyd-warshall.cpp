/**
 * 	Opis: $O(n^3)$. Oblicza odległość między każdą parą wierzchołków w 
 *			  skierowanym grafie ważonym (dopuszczalne wagi ujemne).
 */

vector<vector<int>> floyd-warshall(const vector<vector<pair<int, int>>> &g) {

	int n = ssize(g);
	const int INF = 1e9 + 10;

	vector<vector<int>> d(n, vector<int>(n, INF));

	for (int v = 0; v < n; ++v) {
		d[v][v] = 0;
		for (auto [w, u] : g[v]) 
			d[v][u] = min(d[v][u], w);
	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (d[i][k] < INF && d[k][j] < INF)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	return d;
}
