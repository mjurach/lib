/**
 *	Opis: Trzeba wywołać \texttt{read$\textunderscore$buf()} na początku maina. \newline
 *   	  \textbf{czas:} $0,15$s na time, $772$ms na oiejq.
 */

#include <unistd.h>

const int BUF_IN_SIZE = 200 * 1'024 * 1'024;
char buf_in[BUF_IN_SIZE];
int pos;

bool is_digit(char c) {
	return c >= '0';
}

int fastin(){
	int x = 0;
	char c;
	while (is_digit(c = buf_in[pos++])) {
		x = x * 10 + c - '0';
	}
	return x;
}

void read_buf() {
	read(STDIN_FILENO, buf_in, BUF_IN_SIZE);
	pos = 0;
}
