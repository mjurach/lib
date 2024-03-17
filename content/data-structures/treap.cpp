/**
 * Opis: $O(\log n)$ czasowo. Treap z operacjami na (multi)secie. \texttt{kth(t, k)} zwraca k-tą najmniejszą liczbę.
 */

namespace Treap {
	mt19937 rng(420);
	struct Node {
		Node *left, *right;
		int val, rank;
		int size;
		Node(): left(nullptr), right(nullptr), val(0), rank(int(rng())), size(0) {}
	};
	using pNode = Node*;

	Node pool[1'000'003];
	int curr = 0;

	int sz(pNode t) {
		return t == nullptr ? 0 : t->size;
	}

	void upd(pNode t) {
		t->size = sz(t->left) + sz(t->right) + 1;
	}

	pNode merge(pNode a, pNode b) {
		if(a == nullptr) return b;
		if(b == nullptr) return a;

		if(a->rank < b->rank) {
			a->right = merge(a->right, b);
			upd(a);
			return a;
		}
		else {
			b->left = merge(a, b->left);
			upd(b);
			return b;
		}
	}

	pair<pNode, pNode> split(pNode t, int x) {
		if(t == nullptr) return {nullptr, nullptr};

		if(t->val <= x) {
			auto [a, b] = split(t->right, x);
			t->right = a;
			upd(t);
			return {t, b};
		}
		else {
			auto [a, b] = split(t->left, x);
			t->left = b;
			upd(t);
			return {a, t};
		}
	}

	void insert(pNode &root, int x) {
		pNode u = pool + (curr++);
		u->val = x;
		u->size = 1;
		auto [a, b] = split(root, x);
		root = merge(merge(a, u), b);
	}

	bool find(pNode t, int x) {
		if(t == nullptr) return false;
		if(x == t->val) return true;
		if(x < t->val) return find(t->left, x);
		else return find(t->right, x);
	}

	void erase(pNode root, int x) {
		auto [ab, c] = split(root, x);
		auto [a, b] = split(ab, x-1);
		root = merge(a, c);
	}

	int kth(pNode t, int k) {
		assert(k >= 0);
		if(sz(t->left) == k-1) return t->val;
		if(k > sz(t->left)) return kth(t->right, k-1-sz(t->left));
		else return kth(t->left, k);
	}
}
