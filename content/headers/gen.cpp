/**
 * Opis: Dodatek do generowania testów, lub innego losowania.
 * 		 Zakomentowaną linijkę można dodać na początku main(), 
 * 		 by test \emph{i} zawsze generował to samo.
 */

mt19937 rng(random_device{}());
int rd(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

//rng.seed(atoi(argv[1]))
