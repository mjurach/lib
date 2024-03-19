 /**
  * Opis: \textbf{czas: } ok. $0,67$s na time, $2816$ms na oiejq.
  */

void write_int(unsigned long x) {
	char t[19];
	int i = 0;
	do {
		int d = x%10;
		t[i++] = '0'+d;
		x /= 10;
	} while (x > 0) ;

	while (--i >= 0) {
		putchar_unlocked(t[i]);
	}
	putchar_unlocked('\n');
}
