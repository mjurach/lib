/**
 *	Opis: Ordered set.
 */

#include <ext/pb_ds/assoc_container.hpp> //keep-include
#include <ext/pb_ds/tree_policy.hpp> //keep-include
using namespace __gnu_pbds;

template<typename T> using ordered_set = tree<
T,
null_type,
less<T>,
rb_tree_tag,
tree_order_statistics_node_update>;

void test() {
	ordered_set<int> S;
	S.insert(1);
	cout << *S.find_by_order(0) << '\n'; //zwraca k-ty element (indeksowane od 0)
	cout << (S.end() == find_by_order(1)) << '\n';
	cout << S.order_of_key(4) << '\n'; //zwraca liczbe elementow mniejszych od x
}
