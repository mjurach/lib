/**
 *	 Opis: $O(n)$. Zwraca tablice \texttt{z}, gdzie $\texttt{z}[i]$ jest równe 
 *			najdłuższemu wspólnemu prefiksowi słowa $s$ i sufiksu $[i, \dots, n-1]$.
 */

vector<int> z(string s) {
	int n = ssize(s);
	vector<int> z(n);

	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		if (i < r) z[i] = min(z[i-l], r-i);
		while (i + z[i] < n && s[i+z[i]] == s[z[i]]) ++z[i];
		if (i + z[i] > r) {
			r = i + z[i];
			l = i;
		}
	}
	return z;
}
