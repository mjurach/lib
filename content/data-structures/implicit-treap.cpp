/**
 * Opis: $O(\log n)$ czasowo. Implicit treap z podstawowymi operacjami, przykładowo odwracanie na przedziale (moze być dowolna operacja). 
 * 		 \texttt{insert(root, k, x)} wstawia element o wartości $x$ w $k$-te miejsce tablicy.
 *		 \texttt{rev(root, l, r)} odwraca przedzial $[l; r]$ (indeksy od 0).
 */

namespace Treap {
	mt19937 rng(420);
	struct Node {
		Node *left, *right;
		int rank;
		int size;
		bool rev;
		int val;
		Node(): left(nullptr), right(nullptr), rank(int(rng())), size(0), rev(false), val(0) {}
	};
	using pNode = Node*;

	Node pool[300'003];
	int curr = 0;

	int sz(pNode t) {
		return t == nullptr ? 0 : t->size;
	}

	void upd(pNode t) {
		t->size = sz(t->left) + sz(t->right) + 1;
	}

	void push_lazy(pNode t) {
		if(t->rev == false) return;
		if(t->left) t->left->rev = !t->left->rev;
		if(t->right) t->right->rev = !t->right->rev;
		swap(t->left, t->right);
		t->rev = false;
	}

	pNode merge(pNode a, pNode b) {
		if(a == nullptr) return b;
		if(b == nullptr) return a;

		push_lazy(a);
		push_lazy(b);
		if(a->rank < b->rank) {
			pNode t = merge(a->right, b);
			a->right = t;
			upd(a);
			return a;
		}
		else {
			pNode t = merge(a, b->left);
			b->left = t;
			upd(b);
			return b;
		}
	}

	pair<pNode, pNode> split(pNode t, int x) {
		if(t == nullptr) return {nullptr, nullptr};

		push_lazy(t);
		if(sz(t->left)+1 <= x) {
			auto [a, b] = split(t->right, x-(sz(t->left)+1));
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

	pNode build(vector<int> a) {
		pNode root = nullptr;
		int n = ssize(a);
		for(int i = 0; i < n; ++i) {
			pNode u = pool + i;
			u->size = 1;
			u->val = a[i];
			root = merge(root, u);
		}
		curr += n;
		return root;
	}

	void insert(pNode &root, int k, int x) {
		auto [a, b] = split(root, k-1);
		Node *u = pool + (curr++);
		u->size = 1;
		u->val = x;
		root = merge(merge(a, u), b);
	}

	void reverse(pNode &root, int l, int r) {
		auto [ab, c] = split(root, r+1);
		auto [a, b] = split(ab, l);
		b->rev = !b->rev;
		root = merge(a, merge(b, c));
	}

	void print(pNode t) {
		if(t == nullptr) return;
		push_lazy(t);
		print(t->left);
		cout << t->val << ' ';
		print(t->right);
	}
}
