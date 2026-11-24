/**
 * Opis: Zwraca maksymalny zbiór niezależny
 */

#include "vertex-cover.cpp" //keep-include

vector<bool> independent_set(const vector<vector<int>> &g, const vector<bool> &col) {
	int n = ssize(g);
	vector<bool> s = vertex_cover(g, col);

	for (int i = 0; i < n; ++i) s[i] = !s[i];

	return s;
}
