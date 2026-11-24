/**
 *   Opis: Czas działania: matching + $O(n + m)$. Zwraca czy wierzchołek należy do vertex cover.
 */

#include "matching.cpp" //keep-include

void alt_paths(int v, vector<bool> &s, const vector<int> &mt, const vector<vector<int>> &g) {
	if (s[v]) return;
	s[v] = true;
	for (int u : g[v]) {
		if (mt[u] == -1) continue;
		s[u] = true;
		alt_paths(mt[u], s, mt, g);
	}
}

vector<bool> vertex_cover(const vector<vector<int>> &g, const vector<bool> &col) {
	vector<int> mt = matching(g, col);

	vector<bool> s(n);
	for (int v = 0; v < n; ++v) {
		if (col[v]) continue;
		if (mt[v] == -1) {
			alt_paths(v, s, mt, g);
		}
	}

	for (int v = 0; v < n; ++v) {
		if (!col[v]) s[v] = !s[v];
	}

	return s;
}
