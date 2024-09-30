/**
 * Opis: fastio.
*/


bool is_digit(char c) {
	return c >= '0';
}

int fastin(){
	int x = 0;
	int s = 1;
	char c;
	c = getchar();
	if (c == '-') s = -1;
	else x = c - '0';
	while (is_digit(c = getchar())) {
		x = x * 10 + c - '0';
	}
	return s*x;
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
