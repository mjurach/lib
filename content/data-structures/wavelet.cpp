/**
 * Opis: $O(\log^2 \textrm{ALPH})$, constructor przyjmuje ciąg na którym rozpinamy drzewo,
 * $\textrm{rank(l, r, k)}$ zwraca $k$-tą najmniejszą liczbę na przedziale $[l ; r]$.
 * (\textbf{Uwaga!}) Stała pamięciowa jest dosyć duża (około 262 Mb, dla $N, Q \leq 2\cdot 10^5$).
 */

//funkcja cnt jest w O(\log) co daje cale operacje w O(\log^2), da sie cnt w czasie stalym -- do dopisania
struct wavelet_tree {
	const static int ALPH = (1<<18)-1;
	struct Node {
		int low, high, mid;
		vector<int> v;
		Node *left, *right;

		Node() {
			low = 0, high = ALPH;
			left = right = nullptr;
			mid = (low+high)/2;
		}

		Node (const vector<int> &x, const vector<int> &t, int a = 0, int b = ALPH): low(a), high(b), v(x) {
			mid = ((ll)low+high)/2;
			if(ssize(x) && low != high) {
				vector<int> div[2];
				for(auto e : v) div[t[e]<=mid].eb(e);
				if(ssize(div[1])) left = new Node(div[1], t, low, mid);
				else left = nullptr;
				if(ssize(div[0])) right = new Node(div[0], t, mid+1, high);
				else right = nullptr;
			}
			else {
				left = right = nullptr;
			}
		}
	};

	Node *root;
	wavelet_tree(const vector<int> &b) {
		vector<int> idx;
		REP(i, ssize(b)) idx.eb(i);
		root = new Node(idx, b);
	};

	int cnt(Node *v, int l, int r) {
		if(v == nullptr) return 0;
		return int(upper_bound(all(v->v), r)-lower_bound(all(v->v), l));
	}

	int rank(int l, int r, int k, Node *v) {
		if(v->low == v->high) return v->low;
		if(cnt(v->left, l, r) >= k) return rank(l, r, k, v->left);
		else return rank(l, r, k-cnt(v->left, l, r), v->right);
	}
	int rank(int l, int r, int k) {
		return rank(l, r, k, root);
	}

	void clear(Node *v) {
		if(v->left != nullptr) clear(v->left); 
		if(v->right != nullptr) clear(v->right);
		delete v;
	}
	~wavelet_tree() {
		clear(root);
	}
};
