/**
 * 	 Opis: $O(\log n)$. Dodaj na przedziale, podaj wartość w punkcie.
 */

#include "fenwick-tree.cpp" //keep-include

struct RangeAdd {
	BIT diff;
	RangeAdd(int n): diff(n) {}
	void update(int l, int r, int x) {
		if (l) diff.update(l-1, x);
		diff.update(r, -x);
	}

	int query(int p) {
		return diff.sum(p);
	}
};
