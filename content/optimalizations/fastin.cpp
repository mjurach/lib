/**
 *	Opis: \textbf{czas:} $0,15$s na time, $772$ms na oiejq.
 */

#include <unistd.h>

char buf[200 * 1'024 * 1'024];
int pos;

bool is_digit(char c) {
	return c >= '0';
}

int fastin(){
	int x = 0;
	char c;
	while (is_digit(c = buf[pos++])) {
		x = x * 10 + c - '0';
	}
	return x;
}

void read_all() {
	//wczytuje cale wejscie, mozna wkleic na poczatku maina
	read(STDIN_FILENO, buf, 200 * 1'024 * 1'024);
}
