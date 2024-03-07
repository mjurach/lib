/**
 *	Opis: Trzeba wywołać \texttt{flush$\textunderscore$out()} żeby wszystko wypisać. \\
 *   	  \textbf{czas:} ok. $0,067$s na time, $195$ms na oiejq.
 */

#include <unistd.h>

const int BUF_SIZE = 1'000'100 * 22;
char buf[BUF_SIZE];
char *buf_ptr = buf;

void write_char(char c) {
	*buf_ptr++ = c;
}

constexpr unsigned long 
build_long(char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8) {
	unsigned long n = c8;
	n <<= 8;
	n |= c7;
	n <<= 8;
	n |= c6;
	n <<= 8;
	n |= c5;
	n <<= 8;
	n |= c4;
	n <<= 8;
	n |= c3;
	n <<= 8;
	n |= c2;
	n <<= 8;
	n |= c1;
	return n;
}

template <bool LeadingZeroes> struct output {
	
	constexpr output() {
		char lead = LeadingZeroes ? '0' : ' ';

		for(unsigned long c1 = 1; c1 <= 9; ++c1) 
			for(unsigned long c2 = 0; c2 <= 9; ++c2) 
				for(unsigned long c3 = 0; c3 <= 9; ++c3) 
					for(unsigned long c4 = 0; c4 <= 9; ++c4) 
						for(unsigned long c5 = 0; c5 <= 9; ++c5) 
							arr[10'000*c1+1'000*c2+100*c3+10*c4+c5] = build_long('0'+c1, '0'+c2, '0'+c3, '0'+c4, '0'+c5, '\n', '0', '0');
			
		for(unsigned long c2 = 1; c2 <= 9; ++c2) 
			for(unsigned long c3 = 0; c3 <= 9; ++c3) 
				for(unsigned long c4 = 0; c4 <= 9; ++c4) 
					for(unsigned long c5 = 0; c5 <= 9; ++c5) 
						arr[1'000*c2+100*c3+10*c4+c5] = build_long(lead, '0'+c2, '0'+c3, '0'+c4, '0'+c5, '\n', '0', '0');

		for(unsigned long c3 = 1; c3 <= 9; ++c3) 
			for(unsigned long c4 = 0; c4 <= 9; ++c4) 
				for(unsigned long c5 = 0; c5 <= 9; ++c5) 
					arr[100*c3+10*c4+c5] = build_long(lead, lead, '0'+c3, '0'+c4, '0'+c5, '\n', '0', '0');

		for(unsigned long c4 = 1; c4 <= 9; ++c4) 
			for(unsigned long c5 = 0; c5 <= 9; ++c5) 
				arr[10*c4+c5] = build_long(lead, lead, lead, '0'+c4, '0'+c5, '\n', '0', '0');

		for(unsigned long c5 = 0; c5 <= 9; ++c5) 
			arr[c5] = build_long(lead, lead, lead, lead, '0'+c5, '\n', '0', '0');
	}

	array<unsigned long, 100'000> arr{};
};

constexpr output<true> out_lz;
constexpr output<false> out_ls;

void write_long(unsigned long l, unsigned long n) {
	*reinterpret_cast<unsigned long*> (buf_ptr) = l;
	buf_ptr += n;
}

pair<unsigned long, unsigned long> podziel(unsigned long a, unsigned long b) {
	return {a/b, a%b};
}

void write_int(unsigned long x) {
	if(x >= 1'000'000'000'000'000) {
		auto [abc, d] = podziel(x, 100'000);
		auto [ab, c] = podziel(abc, 100'000);
		auto [a, b] = podziel(ab, 100'000);
		write_long(out_ls.arr[a], 5);
		write_long(out_lz.arr[b], 5);
		write_long(out_lz.arr[c], 5);
		write_long(out_lz.arr[d], 6);
	} else if(x >= 10'000'000'000) {
		auto [ab, c] = podziel(x, 100'000);
		auto [a, b] = podziel(ab, 100'000);
		write_long(out_ls.arr[a], 5);
		write_long(out_lz.arr[b], 5);
		write_long(out_lz.arr[c], 6);
	}
	else if(x >= 100'000) {
		auto [a, b] = podziel(x, 100'000);
		write_long(out_ls.arr[a], 5);
		write_long(out_lz.arr[b], 6);
	} else {
		write_long(out_ls.arr[x], 6);
	}
}

void flush_out() {
	write(STDOUT_FILENO, buf, buf_ptr-buf);
	buf_ptr = buf;
}
