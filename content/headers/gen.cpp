/**
 * Opis: Dodatek do generowania testów, lub innego losowania.
 *		 Ziarno można zmieniać np. \texttt{rng.seed(atoi(argv[1]));}
 */

mt19937 rng(random_device{}());
int rd(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
