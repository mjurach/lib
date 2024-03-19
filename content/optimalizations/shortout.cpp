/**
 *	Opis: Trzeba wywołać \texttt{flush$\textunderscore$out()} żeby wszystko wypisać. \\
 *  	  \textbf{czas:} ok. $0,47$s na time, $1955$ms na oiejq.
 */

#include <unistd.h>

char buf[200 * 1'024 * 1'024];
char *buf_ptr = buf;

void write_char(char c) {
	*buf_ptr++ = c;
}

pair<unsigned long, unsigned long> podziel(unsigned long a, unsigned long b) {
	return {a/b, a%b};
}

void write_int_petla(unsigned long x) {
	do {
		auto [c, d] = podziel(x, 10);
		write_char('0'+d);
		x = c;
	} while (x > 0) ;
}

void write_int(unsigned long x) {
	char  *old_buf_ptr = buf_ptr;
	write_int_petla(x);
	reverse(old_buf_ptr, buf_ptr);
	write_char('\n');
}

void flush() {
	write(STDOUT_FILENO, buf, buf_ptr-buf);
	buf_ptr = buf;
}
