/**
 * Opis: fastio.
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
