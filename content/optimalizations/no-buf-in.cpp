/**
 *	Opis: \textbf{czas:} $0,38$s na time, $1052$ms na oiejq.
 */

bool is_digit(char c) {
	return c >= '0';
}

int fastin(){
	int x = 0;
	char c;
	while (is_digit(c = getchar_unlocked())) {
		x = x * 10 + c - '0';
	}
	return x;
}
